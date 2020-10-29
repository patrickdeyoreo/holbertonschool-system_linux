#ifndef _ELF_ETOH_
#define _ELF_ETOH_

#include <elf.h>
#include <endian.h>

void ehdr32letoh(Elf32_Ehdr *ehdr);
void ehdr32betoh(Elf32_Ehdr *ehdr);
void ehdr64letoh(Elf64_Ehdr *ehdr);
void ehdr64betoh(Elf64_Ehdr *ehdr);

void shdr32letoh(Elf32_Shdr *shdr);
void shdr32betoh(Elf32_Shdr *shdr);
void shdr64letoh(Elf64_Shdr *shdr);
void shdr64betoh(Elf64_Shdr *shdr);

void sym32letoh(Elf32_Sym *sym);
void sym32betoh(Elf32_Sym *sym);
void sym64letoh(Elf64_Sym *sym);
void sym64betoh(Elf64_Sym *sym);

void syminfo32letoh(Elf32_Syminfo *syminfo);
void syminfo32betoh(Elf32_Syminfo *syminfo);
void syminfo64letoh(Elf64_Syminfo *syminfo);
void syminfo64betoh(Elf64_Syminfo *syminfo);

void rel32letoh(Elf32_Rel *rel);
void rel32betoh(Elf32_Rel *rel);
void rel64letoh(Elf64_Rel *rel);
void rel64betoh(Elf64_Rel *rel);

void rela32letoh(Elf32_Rela *rela);
void rela32betoh(Elf32_Rela *rela);
void rela64letoh(Elf64_Rela *rela);
void rela64betoh(Elf64_Rela *rela);

void phdr32letoh(Elf32_Phdr *phdr);
void phdr32betoh(Elf32_Phdr *phdr);
void phdr64letoh(Elf64_Phdr *phdr);
void phdr64betoh(Elf64_Phdr *phdr);

void dyn32letoh(Elf32_Dyn *dyn);
void dyn32betoh(Elf32_Dyn *dyn);
void dyn64letoh(Elf64_Dyn *dyn);
void dyn64betoh(Elf64_Dyn *dyn);

void verdef32letoh(Elf32_Verdef *verdef);
void verdef32betoh(Elf32_Verdef *verdef);
void verdef64letoh(Elf64_Verdef *verdef);
void verdef64betoh(Elf64_Verdef *verdef);

void verdaux32letoh(Elf32_Verdaux *verdaux);
void verdaux32betoh(Elf32_Verdaux *verdaux);
void verdaux64letoh(Elf64_Verdaux *verdaux);
void verdaux64betoh(Elf64_Verdaux *verdaux);

void verneed32letoh(Elf32_Verneed *verneed);
void verneed32betoh(Elf32_Verneed *verneed);
void verneed64letoh(Elf64_Verneed *verneed);
void verneed64betoh(Elf64_Verneed *verneed);

void vernaux32letoh(Elf32_Vernaux *vernaux);
void vernaux32betoh(Elf32_Vernaux *vernaux);
void vernaux64letoh(Elf64_Vernaux *vernaux);
void vernaux64betoh(Elf64_Vernaux *vernaux);

void nhdr32letoh(Elf32_Nhdr *nhdr);
void nhdr32betoh(Elf32_Nhdr *nhdr);
void nhdr64letoh(Elf64_Nhdr *nhdr);
void nhdr64betoh(Elf64_Nhdr *nhdr);

void move32letoh(Elf32_Move *move);
void move32betoh(Elf32_Move *move);
void move64letoh(Elf64_Move *move);
void move64betoh(Elf64_Move *move);

void lib32letoh(Elf32_Lib *lib);
void lib32betoh(Elf32_Lib *lib);
void lib64letoh(Elf64_Lib *lib);
void lib64betoh(Elf64_Lib *lib);

#endif /* _ELF_ETOH_ */
