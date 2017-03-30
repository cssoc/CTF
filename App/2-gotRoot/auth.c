#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>

int main (int argc, char** argv)
{
	struct authStruct {
		int auth;
		uid_t ruid;
		uid_t euid;
	} auth1;

	struct authStruct *authPtr = &auth1;

	if (argc < 3)
	{
		printf("%s", "Please supply the files you want to encrypt and the key!\n");
		return 1;
	}

	authPtr->ruid = getuid();
	authPtr->euid = geteuid();
	authPtr->auth = authPtr->ruid == authPtr->euid;
	printf("You want to encrypt ");
	printf(argv[1]);
	printf(" with the key ");
	printf(argv[2]);

	printf(" your real userid %d and your effective userid %d", authPtr->ruid, authPtr->euid);
	if (!authPtr->auth)
		printf("%s", " didn't match and as a result you won't be able to encrypt the file\n");
	else
		printf("%s", " did match and you will see the enrcrypted output in STDOUT if you have read permissions for the file\n");

	if (authPtr->auth)
	{
		char flagChar;
		FILE* flag;
		if ((flag = fopen(argv[1], "r")) != NULL)
		{
			int keyLength = strlen(argv[2] - 1);
			int i = 0;
			while ((flagChar = getc(flag)) != EOF)
			{
				flagChar = (i < keyLength) ? argv[2][i++] ^ flagChar : argv[2][i=0] ^ flagChar;
				printf("%c", flagChar);
			}
			printf("\n");
			fclose(flag);
		}
	}
	if (errno)
		perror("there were errors!");
	return errno;
}
