#ifndef _LOAD_H_
#define _LOAD_H_

#include <elf.h>
#include <stdio.h>

#include "etoh.h"

#define LOADFNTABSIZE 15

/**
 * enum loadfntabidx_e - loadfntab index enum
 *
 * @ehdrloadfntabidx: ehdr loading function index
 * @shdrloadfntabidx: shdr loading function index
 * @symloadfntabidx: sym loading function index
 * @syminfoloadfntabidx: syminfo loading function index
 * @relloadfntabidx: rel loading function index
 * @relaloadfntabidx: rela loading function index
 * @phdrloadfntabidx: phdr loading function index
 * @dynloadfntabidx: dyn loading function index
 * @verdefloadfntabidx: verdef loading function index
 * @verdauxloadfntabidx: verdaux loading function index
 * @verneedloadfntabidx: verneed loading function index
 * @vernauxloadfntabidx: vernaux loading function index
 * @nhdrloadfntabidx: nhdr loading function index
 * @moveloadfntabidx: move loading function index
 * @libloadfntabidx: lib loading function index
 */
enum loadfntabidx_e
{
	ehdrloadfntabidx = 0,
	shdrloadfntabidx,
	symloadfntabidx,
	syminfoloadfntabidx,
	relloadfntabidx,
	relaloadfntabidx,
	phdrloadfntabidx,
	dynloadfntabidx,
	verdefloadfntabidx,
	verdauxloadfntabidx,
	verneedloadfntabidx,
	vernauxloadfntabidx,
	nhdrloadfntabidx,
	moveloadfntabidx,
	libloadfntabidx
};

typedef int (*loadfn_t)(const char *, void *);

void loadfntabinit32le(loadfn_t (*loadfntab)[LOADFNTABSIZE]);
void loadfntabinit32be(loadfn_t (*loadfntab)[LOADFNTABSIZE]);
void loadfntabinit64le(loadfn_t (*loadfntab)[LOADFNTABSIZE]);
void loadfntabinit64be(loadfn_t (*loadfntab)[LOADFNTABSIZE]);

int ehdr32leload(const char *filename, Elf32_Ehdr *ehdr);
int ehdr32beload(const char *filename, Elf32_Ehdr *ehdr);
int ehdr64leload(const char *filename, Elf64_Ehdr *ehdr);
int ehdr64beload(const char *filename, Elf64_Ehdr *ehdr);

int shdr32leload(const char *filename, Elf32_Shdr *shdr);
int shdr32beload(const char *filename, Elf32_Shdr *shdr);
int shdr64leload(const char *filename, Elf64_Shdr *shdr);
int shdr64beload(const char *filename, Elf64_Shdr *shdr);

int sym32leload(const char *filename, Elf32_Sym *sym);
int sym32beload(const char *filename, Elf32_Sym *sym);
int sym64leload(const char *filename, Elf64_Sym *sym);
int sym64beload(const char *filename, Elf64_Sym *sym);

int syminfo32leload(const char *filename, Elf32_Syminfo *syminfo);
int syminfo32beload(const char *filename, Elf32_Syminfo *syminfo);
int syminfo64leload(const char *filename, Elf64_Syminfo *syminfo);
int syminfo64beload(const char *filename, Elf64_Syminfo *syminfo);

int rel32leload(const char *filename, Elf32_Rel *rel);
int rel32beload(const char *filename, Elf32_Rel *rel);
int rel64leload(const char *filename, Elf64_Rel *rel);
int rel64beload(const char *filename, Elf64_Rel *rel);

int rela32leload(const char *filename, Elf32_Rela *rela);
int rela32beload(const char *filename, Elf32_Rela *rela);
int rela64leload(const char *filename, Elf64_Rela *rela);
int rela64beload(const char *filename, Elf64_Rela *rela);

int phdr32leload(const char *filename, Elf32_Phdr *phdr);
int phdr32beload(const char *filename, Elf32_Phdr *phdr);
int phdr64leload(const char *filename, Elf64_Phdr *phdr);
int phdr64beload(const char *filename, Elf64_Phdr *phdr);

int dyn32leload(const char *filename, Elf32_Dyn *dyn);
int dyn32beload(const char *filename, Elf32_Dyn *dyn);
int dyn64leload(const char *filename, Elf64_Dyn *dyn);
int dyn64beload(const char *filename, Elf64_Dyn *dyn);

int verdef32leload(const char *filename, Elf32_Verdef *verdef);
int verdef32beload(const char *filename, Elf32_Verdef *verdef);
int verdef64leload(const char *filename, Elf64_Verdef *verdef);
int verdef64beload(const char *filename, Elf64_Verdef *verdef);

int verdaux32leload(const char *filename, Elf32_Verdaux *verdaux);
int verdaux32beload(const char *filename, Elf32_Verdaux *verdaux);
int verdaux64leload(const char *filename, Elf64_Verdaux *verdaux);
int verdaux64beload(const char *filename, Elf64_Verdaux *verdaux);

int verneed32leload(const char *filename, Elf32_Verneed *verneed);
int verneed32beload(const char *filename, Elf32_Verneed *verneed);
int verneed64leload(const char *filename, Elf64_Verneed *verneed);
int verneed64beload(const char *filename, Elf64_Verneed *verneed);

int vernaux32leload(const char *filename, Elf32_Vernaux *vernaux);
int vernaux32beload(const char *filename, Elf32_Vernaux *vernaux);
int vernaux64leload(const char *filename, Elf64_Vernaux *vernaux);
int vernaux64beload(const char *filename, Elf64_Vernaux *vernaux);

int nhdr32leload(const char *filename, Elf32_Nhdr *nhdr);
int nhdr32beload(const char *filename, Elf32_Nhdr *nhdr);
int nhdr64leload(const char *filename, Elf64_Nhdr *nhdr);
int nhdr64beload(const char *filename, Elf64_Nhdr *nhdr);

int move32leload(const char *filename, Elf32_Move *move);
int move32beload(const char *filename, Elf32_Move *move);
int move64leload(const char *filename, Elf64_Move *move);
int move64beload(const char *filename, Elf64_Move *move);

int lib32leload(const char *filename, Elf32_Lib *lib);
int lib32beload(const char *filename, Elf32_Lib *lib);
int lib64leload(const char *filename, Elf64_Lib *lib);
int lib64beload(const char *filename, Elf64_Lib *lib);

#endif /* _LOAD_H_ */
