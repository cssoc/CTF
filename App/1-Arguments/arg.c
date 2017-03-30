#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	//ensure that user guessed the flag
	if (argc < 2)
	{
		fprintf(stderr, "Please guess the flag!\n");
		exit(1);
	}

	FILE* flagFile = fopen("flag.txt","r");
	//handle errors
	if (errno)
	{
		perror("Something went wrong :(");
		exit(EXIT_FAILURE);
	}

	//determine size of the flagfile
	fseek(flagFile, 0L, SEEK_END);
	int flagSize = ftell(flagFile);
	rewind(flagFile);
	
	//allocate memory on the stack for the flag
	//and let flag point to said memory
	char* flag = alloca(flagSize);

	//write flag to memory pointed to by flag
	fread(flag, 1, flagSize, flagFile);
	fclose(flagFile);
	
	//replace newline char with null char
	flag[flagSize - 1] = '\0';

	printf("You guessed\n");
	printf(argv[1]);
	if (!strcmp(argv[1], flag))
		printf("\nand you were right!\n");
	else
		printf("\nbut you were wrong!\n");

	return 0;
}
