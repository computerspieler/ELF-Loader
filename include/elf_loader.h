#ifndef __ELF_LOADER_H__
#define __ELF_LOADER_H__

typedef unsigned char	uint8_t;
typedef unsigned short	uint16_t;
typedef unsigned int	uint32_t;

typedef struct ELF_Header ELF_Header;
typedef struct ELF_Program_Header ELF_Program_Header;
typedef struct ELF_Section_Header ELF_Section_Header;

struct ELF_Header
{
	struct
	{
		uint32_t magic;
		uint8_t class;
		uint8_t endianness;
		uint8_t version;
		uint8_t abi;
		uint8_t abi_version;
		uint8_t pad[7];
	} identifier __attribute__((packed));

	uint16_t type;
	uint16_t machine;
	uint32_t version;
	uint32_t entry;
	uint32_t program_header_table;
	uint32_t section_header_table;
	uint32_t flags;
	uint16_t header_size;
	uint16_t program_header_size;
	uint16_t program_header_count;
	uint16_t section_header_size;
	uint16_t section_header_count;
	uint16_t section_header_index_names;
} __attribute__((packed));

struct ELF_Program_Header
{
	uint32_t segment_type;
	uint32_t p_offset;
	uint32_t p_virtual_address;
	uint32_t undefined_for_system_v;
	uint32_t p_file_size;
	uint32_t p_mem_size;
	uint32_t flags;
	uint8_t alignment[4];
} __attribute__((packed));

struct ELF_Section_Header
{
	char name[4];
	uint32_t type;
	uint32_t flags;
	uint32_t address;
	uint32_t offset;
	uint32_t size;
	uint32_t link;
	uint32_t info;
	uint32_t address_align;
	uint32_t entry_size;
} __attribute__((packed));

int elf_print_info(char* elf_data, size_t size);

#endif