#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if (argc < 3)
	{
		fprintf(stderr, "Please provide file and key!(in that order)\n");
		exit(1);
	}

	int key = atoi(argv[2]);
	if (!key)
	{
		fprintf(stderr, "Key is invalid!");
		exit(1);
	}

	FILE* input = fopen(argv[1],"r");
	//handle errors
	if (errno)
	{
		perror("Something went wrong :(");
		exit(EXIT_FAILURE);
	}

	//determine size of the input
	fseek(input, 0L, SEEK_END);
	int inputSize = ftell(input);
	rewind(input);
	
	FILE* output = fopen("output.enc", "w");

	for(int byte = 0; byte < inputSize; byte++)
	{
		fputc(fgetc(input) + key, output);
	}
	
	if (errno)
	{
		perror("Something went wrong :(");
		exit(EXIT_FAILURE);
	}

	fclose(input);
	fclose(output);
	printf("Done!");

	return 0;
}
