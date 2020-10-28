#include "hreadelf.h"

/**
 * readelf_32 - handle a 32-bit elf header
 *
 * @argv: argument vector
 *
 * Return: 1 if an error occurs, otherwise 0
 */
static int readelf_32(char **argv)
{
	Elf32_Ehdr ehdr;
	FILE *istream = fopen(argv[1], "r");

	if (!istream || fread(&ehdr, sizeof(ehdr), 1, istream) != 1)
	{
		fprintf(stderr, "%s: Error: Can't read from file\n", *argv);
		return (1);
	}
	fclose(istream);
	elf_type(ehdr.e_type);
	elf_machine(ehdr.e_machine);
	elf_version(ehdr.e_version);
	elf_entry(ehdr.e_entry);
	elf_phoff(ehdr.e_phoff);
	elf_shoff(ehdr.e_shoff);
	elf_flags(ehdr.e_flags);
	elf_ehsize(ehdr.e_ehsize);
	elf_phentsize(ehdr.e_phentsize);
	elf_phnum(ehdr.e_phnum);
	elf_shentsize(ehdr.e_shentsize);
	elf_shnum(ehdr.e_shnum);
	elf_shstrndx(ehdr.e_shstrndx);
	return (0);
}

/**
 * readelf_64 - handle a 64-bit ELF header
 *
 * @argv: argument vector
 *
 * Return: 1 if an error occurs, otherwise 0
 */
static int readelf_64(char **argv)
{
	Elf64_Ehdr ehdr;
	FILE *istream = fopen(argv[1], "r");

	if (!istream || fread(&ehdr, sizeof(ehdr), 1, istream) != 1)
	{
		fprintf(stderr, "%s: Error: Can't read from file\n", *argv);
		return (1);
	}
	fclose(istream);
	elf_type(ehdr.e_type);
	elf_machine(ehdr.e_machine);
	elf_version(ehdr.e_version);
	elf_entry(ehdr.e_entry);
	elf_phoff(ehdr.e_phoff);
	elf_shoff(ehdr.e_shoff);
	elf_flags(ehdr.e_flags);
	elf_ehsize(ehdr.e_ehsize);
	elf_phentsize(ehdr.e_phentsize);
	elf_phnum(ehdr.e_phnum);
	elf_shentsize(ehdr.e_shentsize);
	elf_shnum(ehdr.e_shnum);
	elf_shstrndx(ehdr.e_shstrndx);
	return (0);
}

/**
 * main - parse an elf file header
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 1 if an error occurs, otherwise 0
 */
int main(int argc, char **argv)
{
	unsigned char e_ident[EI_NIDENT] = {0};
	FILE *istream = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", *argv);
		return (1);
	}
	istream = fopen(argv[1], "r");
	if (!istream || fread(e_ident, 1, EI_NIDENT, istream) != EI_NIDENT)
	{
		fprintf(stderr, "%s: Error: Can't read from file\n", *argv);
		return (1);
	}
	fclose(istream);
	if (memcmp(e_ident, ELFMAG, SELFMAG))
	{
		fprintf(stderr, "%s: Error: Not an ELF file\n", *argv);
		return (1);
	}
	elf_ident(&e_ident);
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		return (readelf_32(argv));
	case ELFCLASS64:
		return (readelf_64(argv));
	default:
		fprintf(stderr, "%s: Error: Unknown ELF class\n", *argv);
		return (1);
	}
}
