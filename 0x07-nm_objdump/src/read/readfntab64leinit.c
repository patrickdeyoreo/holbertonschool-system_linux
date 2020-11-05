#include "../read.h"

/**
 * readfntab64leinit - initialize an array of pointers to ELF reading functions
 *
 * @readfntab: pointer to the array to initialize
 */
void readfntab64leinit(readfn_t (*readfntab)[READFNTABSZ])
{
	if (readfntab)
	{
		(*readfntab)[ehdrreadfnidx] = (readfn_t) ehdr64leread;
		(*readfntab)[shdrreadfnidx] = (readfn_t) shdr64leread;
		(*readfntab)[symreadfnidx] = (readfn_t) sym64leread;
		(*readfntab)[syminforeadfnidx] = (readfn_t) syminfo64leread;
		(*readfntab)[relreadfnidx] = (readfn_t) rel64leread;
		(*readfntab)[relareadfnidx] = (readfn_t) rela64leread;
		(*readfntab)[phdrreadfnidx] = (readfn_t) phdr64leread;
		(*readfntab)[dynreadfnidx] = (readfn_t) dyn64leread;
		(*readfntab)[verdefreadfnidx] = (readfn_t) verdef64leread;
		(*readfntab)[verdauxreadfnidx] = (readfn_t) verdaux64leread;
		(*readfntab)[verneedreadfnidx] = (readfn_t) verneed64leread;
		(*readfntab)[vernauxreadfnidx] = (readfn_t) vernaux64leread;
		(*readfntab)[nhdrreadfnidx] = (readfn_t) nhdr64leread;
		(*readfntab)[movereadfnidx] = (readfn_t) move64leread;
		(*readfntab)[libreadfnidx] = (readfn_t) lib64leread;
	}
}
