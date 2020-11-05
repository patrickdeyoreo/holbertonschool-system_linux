#ifndef _READ_H_
#define _READ_H_

#include <elf.h>
#include <stdio.h>

#include "etoh.h"

#define READFNTABSZ 15

/**
 * enum readfnidx_e - readfntab index enum
 *
 * @ehdrreadfnidx: ehdr reading function index
 * @shdrreadfnidx: shdr reading function index
 * @symreadfnidx: sym reading function index
 * @syminforeadfnidx: syminfo reading function index
 * @relreadfnidx: rel reading function index
 * @relareadfnidx: rela reading function index
 * @phdrreadfnidx: phdr reading function index
 * @dynreadfnidx: dyn reading function index
 * @verdefreadfnidx: verdef reading function index
 * @verdauxreadfnidx: verdaux reading function index
 * @verneedreadfnidx: verneed reading function index
 * @vernauxreadfnidx: vernaux reading function index
 * @nhdrreadfnidx: nhdr reading function index
 * @movereadfnidx: move reading function index
 * @libreadfnidx: lib reading function index
 */
enum readfnidx_e
{
	ehdrreadfnidx = 0,
	shdrreadfnidx,
	symreadfnidx,
	syminforeadfnidx,
	relreadfnidx,
	relareadfnidx,
	phdrreadfnidx,
	dynreadfnidx,
	verdefreadfnidx,
	verdauxreadfnidx,
	verneedreadfnidx,
	vernauxreadfnidx,
	nhdrreadfnidx,
	movereadfnidx,
	libreadfnidx
};

typedef int (*readfn_t)(void *, FILE *);

void readfntab32leinit(readfn_t (*readfntab)[READFNTABSZ]);
void readfntab32beinit(readfn_t (*readfntab)[READFNTABSZ]);
void readfntab64leinit(readfn_t (*readfntab)[READFNTABSZ]);
void readfntab64beinit(readfn_t (*readfntab)[READFNTABSZ]);

int ehdr32leread(Elf32_Ehdr *ehdr, FILE *istream);
int ehdr32beread(Elf32_Ehdr *ehdr, FILE *istream);
int ehdr64leread(Elf64_Ehdr *ehdr, FILE *istream);
int ehdr64beread(Elf64_Ehdr *ehdr, FILE *istream);

int shdr32leread(Elf32_Shdr *shdr, FILE *istream);
int shdr32beread(Elf32_Shdr *shdr, FILE *istream);
int shdr64leread(Elf64_Shdr *shdr, FILE *istream);
int shdr64beread(Elf64_Shdr *shdr, FILE *istream);

int sym32leread(Elf32_Sym *sym, FILE *istream);
int sym32beread(Elf32_Sym *sym, FILE *istream);
int sym64leread(Elf64_Sym *sym, FILE *istream);
int sym64beread(Elf64_Sym *sym, FILE *istream);

int syminfo32leread(Elf32_Syminfo *syminfo, FILE *istream);
int syminfo32beread(Elf32_Syminfo *syminfo, FILE *istream);
int syminfo64leread(Elf64_Syminfo *syminfo, FILE *istream);
int syminfo64beread(Elf64_Syminfo *syminfo, FILE *istream);

int rel32leread(Elf32_Rel *rel, FILE *istream);
int rel32beread(Elf32_Rel *rel, FILE *istream);
int rel64leread(Elf64_Rel *rel, FILE *istream);
int rel64beread(Elf64_Rel *rel, FILE *istream);

int rela32leread(Elf32_Rela *rela, FILE *istream);
int rela32beread(Elf32_Rela *rela, FILE *istream);
int rela64leread(Elf64_Rela *rela, FILE *istream);
int rela64beread(Elf64_Rela *rela, FILE *istream);

int phdr32leread(Elf32_Phdr *phdr, FILE *istream);
int phdr32beread(Elf32_Phdr *phdr, FILE *istream);
int phdr64leread(Elf64_Phdr *phdr, FILE *istream);
int phdr64beread(Elf64_Phdr *phdr, FILE *istream);

int dyn32leread(Elf32_Dyn *dyn, FILE *istream);
int dyn32beread(Elf32_Dyn *dyn, FILE *istream);
int dyn64leread(Elf64_Dyn *dyn, FILE *istream);
int dyn64beread(Elf64_Dyn *dyn, FILE *istream);

int verdef32leread(Elf32_Verdef *verdef, FILE *istream);
int verdef32beread(Elf32_Verdef *verdef, FILE *istream);
int verdef64leread(Elf64_Verdef *verdef, FILE *istream);
int verdef64beread(Elf64_Verdef *verdef, FILE *istream);

int verdaux32leread(Elf32_Verdaux *verdaux, FILE *istream);
int verdaux32beread(Elf32_Verdaux *verdaux, FILE *istream);
int verdaux64leread(Elf64_Verdaux *verdaux, FILE *istream);
int verdaux64beread(Elf64_Verdaux *verdaux, FILE *istream);

int verneed32leread(Elf32_Verneed *verneed, FILE *istream);
int verneed32beread(Elf32_Verneed *verneed, FILE *istream);
int verneed64leread(Elf64_Verneed *verneed, FILE *istream);
int verneed64beread(Elf64_Verneed *verneed, FILE *istream);

int vernaux32leread(Elf32_Vernaux *vernaux, FILE *istream);
int vernaux32beread(Elf32_Vernaux *vernaux, FILE *istream);
int vernaux64leread(Elf64_Vernaux *vernaux, FILE *istream);
int vernaux64beread(Elf64_Vernaux *vernaux, FILE *istream);

int nhdr32leread(Elf32_Nhdr *nhdr, FILE *istream);
int nhdr32beread(Elf32_Nhdr *nhdr, FILE *istream);
int nhdr64leread(Elf64_Nhdr *nhdr, FILE *istream);
int nhdr64beread(Elf64_Nhdr *nhdr, FILE *istream);

int move32leread(Elf32_Move *move, FILE *istream);
int move32beread(Elf32_Move *move, FILE *istream);
int move64leread(Elf64_Move *move, FILE *istream);
int move64beread(Elf64_Move *move, FILE *istream);

int lib32leread(Elf32_Lib *lib, FILE *istream);
int lib32beread(Elf32_Lib *lib, FILE *istream);
int lib64leread(Elf64_Lib *lib, FILE *istream);
int lib64beread(Elf64_Lib *lib, FILE *istream);

#endif /* _READ_H_ */
