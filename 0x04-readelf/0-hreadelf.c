#include <endian.h>
#include <libgen.h>

#include "hreadelf.h"

/**
 * readelf_32_etoh - convert 32-bit ELF header data to host byte order
 *
 * @ehdr: pointer to 32-bit elf header
 */
static void readelf_32_etoh(Elf32_Ehdr *ehdr)
{
	switch (ehdr->e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		ehdr->e_type = le16toh(ehdr->e_type);
		ehdr->e_machine = le16toh(ehdr->e_machine);
		ehdr->e_version = le32toh(ehdr->e_version);
		ehdr->e_entry = le32toh(ehdr->e_entry);
		ehdr->e_phoff = le32toh(ehdr->e_phoff);
		ehdr->e_shoff = le32toh(ehdr->e_shoff);
		ehdr->e_flags = le32toh(ehdr->e_flags);
		ehdr->e_ehsize = le16toh(ehdr->e_ehsize);
		ehdr->e_phentsize = le16toh(ehdr->e_phentsize);
		ehdr->e_phnum = le16toh(ehdr->e_phnum);
		ehdr->e_shentsize = le16toh(ehdr->e_shentsize);
		ehdr->e_shnum = le16toh(ehdr->e_shnum);
		ehdr->e_shstrndx = le16toh(ehdr->e_shstrndx);
		break;
	case ELFDATA2MSB:
		ehdr->e_type = be16toh(ehdr->e_type);
		ehdr->e_machine = be16toh(ehdr->e_machine);
		ehdr->e_version = be32toh(ehdr->e_version);
		ehdr->e_entry = be32toh(ehdr->e_entry);
		ehdr->e_phoff = be32toh(ehdr->e_phoff);
		ehdr->e_shoff = be32toh(ehdr->e_shoff);
		ehdr->e_flags = be32toh(ehdr->e_flags);
		ehdr->e_ehsize = be16toh(ehdr->e_ehsize);
		ehdr->e_phentsize = be16toh(ehdr->e_phentsize);
		ehdr->e_phnum = be16toh(ehdr->e_phnum);
		ehdr->e_shentsize = be16toh(ehdr->e_shentsize);
		ehdr->e_shnum = be16toh(ehdr->e_shnum);
		ehdr->e_shstrndx = be16toh(ehdr->e_shstrndx);
		break;
	}
}

/**
 * readelf_64_etoh - convert 64-bit ELF header data to host byte order
 *
 * @ehdr: pointer to 64-bit elf header
 */
static void readelf_64_etoh(Elf64_Ehdr *ehdr)
{
	switch (ehdr->e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		ehdr->e_type = le16toh(ehdr->e_type);
		ehdr->e_machine = le16toh(ehdr->e_machine);
		ehdr->e_version = le32toh(ehdr->e_version);
		ehdr->e_entry = le64toh(ehdr->e_entry);
		ehdr->e_phoff = le64toh(ehdr->e_phoff);
		ehdr->e_shoff = le64toh(ehdr->e_shoff);
		ehdr->e_flags = le32toh(ehdr->e_flags);
		ehdr->e_ehsize = le16toh(ehdr->e_ehsize);
		ehdr->e_phentsize = le16toh(ehdr->e_phentsize);
		ehdr->e_phnum = le16toh(ehdr->e_phnum);
		ehdr->e_shentsize = le16toh(ehdr->e_shentsize);
		ehdr->e_shnum = le16toh(ehdr->e_shnum);
		ehdr->e_shstrndx = le16toh(ehdr->e_shstrndx);
		break;
	case ELFDATA2MSB:
		ehdr->e_type = be16toh(ehdr->e_type);
		ehdr->e_machine = be16toh(ehdr->e_machine);
		ehdr->e_version = be32toh(ehdr->e_version);
		ehdr->e_entry = be64toh(ehdr->e_entry);
		ehdr->e_phoff = be64toh(ehdr->e_phoff);
		ehdr->e_shoff = be64toh(ehdr->e_shoff);
		ehdr->e_flags = be32toh(ehdr->e_flags);
		ehdr->e_ehsize = be16toh(ehdr->e_ehsize);
		ehdr->e_phentsize = be16toh(ehdr->e_phentsize);
		ehdr->e_phnum = be16toh(ehdr->e_phnum);
		ehdr->e_shentsize = be16toh(ehdr->e_shentsize);
		ehdr->e_shnum = be16toh(ehdr->e_shnum);
		ehdr->e_shstrndx = be16toh(ehdr->e_shstrndx);
		break;
	}
}

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
		fprintf(stderr, "%s: Error: Can't read from file\n",
			basename(argv[0]));
		return (1);
	}
	fclose(istream);
	readelf_32_etoh(&ehdr);
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
		fprintf(stderr, "%s: Error: Can't read from file\n",
			basename(argv[0]));
		return (1);
	}
	fclose(istream);
	readelf_64_etoh(&ehdr);
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
		fprintf(stderr, "Usage: %s elf_filename\n",
			basename(argv[0]));
		return (1);
	}
	istream = fopen(argv[1], "r");
	if (!istream || fread(e_ident, 1, EI_NIDENT, istream) != EI_NIDENT)
	{
		fprintf(stderr, "%s: Error: Can't read from file\n",
			basename(argv[0]));
		return (1);
	}
	fclose(istream);
	if (memcmp(e_ident, ELFMAG, SELFMAG))
	{
		fprintf(stderr, "%s: Error: Not an ELF file\n",
			basename(argv[0]));
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
		fprintf(stderr, "%s: Error: Unknown ELF class %x at byte %d\n",
			basename(argv[0]), e_ident[EI_CLASS], EI_CLASS);
		return (1);
	}
}
