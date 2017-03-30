#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>

#define PORT 6666
#define MAX_CON 5
#define MAXMSG 128

int makeSocket (void)
{
	int sock = socket (PF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		perror("Failed creating socket");
		exit(EXIT_FAILURE);
	}
	return sock;
}

void bindSocket(int socket)
{
	struct sockaddr_in name;
	name.sin_family = AF_INET;
	name.sin_port = htons(PORT);
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if(bind(socket, (struct sockaddr *) &name, sizeof (name)) < 0)
	{
		perror("Failed binding");
		exit(EXIT_FAILURE);
	}
}

void handleErrors(void)
{

	ERR_print_errors_fp(stderr);
	abort();
}

int readClient(int client,unsigned char* iv,unsigned char * key)
{
	ERR_load_crypto_strings();
	OpenSSL_add_all_algorithms();
	OPENSSL_config(NULL);

	EVP_CIPHER_CTX *ctx;

	int len = 0;

	struct timeval timeout;
	timeout.tv_sec = 1;
	timeout.tv_usec = 0;

	if(setsockopt(client, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout,
				sizeof(timeout)) < 0)
		perror("setsockopt failed");

	if(setsockopt(client, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout,
				sizeof(timeout)) < 0)
		perror("setsockopt failed");

	//int plaintext_len = 0;

	if(!(ctx = EVP_CIPHER_CTX_new()))
		handleErrors();


	//unsigned char key[32];
//29235b514a5d9df1e6ed6d611bbb155c03e6025d483b4d12ffe4dc568d3aa401;
	//unsigned char iv[16];
		//91bd3110a1570d20;//810d8d76d3167bfa;


	if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
		handleErrors();

	unsigned char buffer[MAXMSG];
	unsigned char clearText[256];
	int nbytes;
	int total = 0;
	while((nbytes = read(client, buffer, MAXMSG)))
	{
		//printf("received %d encrypted bytes...\n", nbytes);
                //total += nbytes;
		//fprintf(stderr, "%d \n", len);
		if (nbytes < 0)
		{
			perror ("read");
			exit (EXIT_FAILURE);
		}
		else 
		{
			if(1 != EVP_DecryptUpdate(ctx, clearText, &len, buffer, nbytes))
			{
				handleErrors();
			}
			//total += len;
		        //fprintf(stderr,"decrypted %d bytes... %d \n", len, nbytes);
		}
		//!
		write(1, clearText, len);
	}

        //fprintf(stderr, "received in total %d bytes\n", total);

	if(1 != EVP_DecryptFinal_ex(ctx, clearText, &len))
	{
		char * err = "\x01\x00";
		write(client, err, 2);
		close(client);
		handleErrors();
	}	
	for (int printed = 0; printed < len; printed++)
		printf("%c", clearText[printed]);

	EVP_CIPHER_CTX_free(ctx);

	EVP_cleanup();
	CRYPTO_cleanup_all_ex_data();
	ERR_free_strings();
	
	fprintf(stderr, "success\n");
	char * ok = "\x00\x00";
	write(client, ok, 2);

	return 0;
}

int main (int argc, char *argv[])
{
	//fd_set activeFdSet, readFdSet;

	unsigned char iv[16];
	unsigned char key[32];

	FILE * keyFD = fopen("key", "rb");
	if (fread(key, 1, 32, keyFD) != 32)
	{
		perror("Failed reading key");
		exit(EXIT_FAILURE);
	}

	FILE * ivFD = fopen("iv", "rb");
	if (fread(iv, 1, 16, ivFD) != 16)
	{
		perror("Failed reading IV");
		exit(EXIT_FAILURE);
	}
	fclose(ivFD);
	fclose(keyFD);

	int socket = makeSocket();
	bindSocket(socket);	

	if(listen(socket, MAX_CON))
	{
		perror("Failed listening");
		exit(EXIT_FAILURE);
	}
	
	struct sockaddr_in client;
	socklen_t clen;

	//FD_ZERO (&activeFdSet);
	//FD_SET (socket, &activeFdSet);

	while(1)
	{
		//readFdSet = activeFdSet;
		
		//if (select (FD_SETSIZE, &readFdSet, NULL, NULL, NULL) < 0)
		//{
		//	perror ("select");
		//	exit (EXIT_FAILURE);
		//}

		//for (int i = 0; i < FD_SETSIZE; ++i)
		//{
		//	if(FD_ISSET(i, &readFdSet))
		//	{
		//		if(i == socket)
		//		{
		int newSocket = accept(socket,
			(struct sockaddr *) &client,
			&clen);
		if (newSocket < 0)
			{
				perror ("accept");
				exit (EXIT_FAILURE);
			}

	//	printf("Connection from %i port %i",
	//		ntohl(client.sin_addr.s_addr),
	//		ntohs(client.sin_port));
		int pid = fork();
		if(pid < 0)
		{
			perror("Failed forking");
			exit(EXIT_FAILURE);
		}
		else if(pid == 0)
		{
			close(socket);
			readClient(newSocket, iv, key);
			close(newSocket);
			exit(0);
		}
		else
		{
			close(newSocket);
			int a;
			wait(&a);
		}
				//FD_SET (newSocket, &activeFdSet);
				/*}
				else
				{
					if (readClient(newSocket))
					{
						close(newSocket);
						FD_CLR (newSocket, &activeFdSet);
					}
				}
			}
		}
		*/
	}
}
