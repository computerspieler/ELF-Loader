#include <stdio.h>
#include <stdlib.h>

#include "elf_loader.h"

int main(int argc, char* argv[])
{
	FILE* elf_file;
	long elf_size;
	char* elf_data;

	if(argc != 2)
		exit(EXIT_FAILURE);

	elf_file = fopen(argv[1], "r");
	if(!elf_file)
	{
		perror("fopen");	
		exit(EXIT_FAILURE);
	}

	fseek(elf_file, 0, SEEK_END);
	elf_size = ftell(elf_file);
	rewind(elf_file);

	elf_data = (char*) calloc(elf_size + 1, sizeof(char));
	if(!elf_data)
	{
		perror("calloc");	
		fclose(elf_file);
		exit(EXIT_FAILURE);
	}

	if(fread(elf_data, sizeof(char), elf_size, elf_file) != elf_size)
	{
		perror("fread");	
		fclose(elf_file);
		free(elf_data);
		exit(EXIT_FAILURE);
	}
	fclose(elf_file);

	printf("%i\n", elf_print_info(elf_data, elf_size));

	free(elf_data);

	return 0;
}
