#include <stdio.h>
#include <string.h>

#include "elf_loader.h"

int elf_print_info(char* elf_data, size_t size)
{
	ELF_Header header;
	ELF_Program_Header program_header;

	if(size < sizeof(ELF_Header))
		return 2;

	memcpy(&header, elf_data, sizeof(ELF_Header));

	// 0x464c457F = "\x7FELF" in LSB
	if(header.identifier.magic != 0x464c457F)
		return 1;

	memcpy(&program_header, elf_data + header.program_header_table, sizeof(ELF_Program_Header));


	return 0;
}