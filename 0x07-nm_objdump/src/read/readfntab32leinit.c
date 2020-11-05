#include "../read.h"

/**
 * readfntab32leinit - initialize an array of pointers to ELF reading functions
 *
 * @readfntab: pointer to the array to initialize
 */
void readfntab32leinit(readfn_t (*readfntab)[READFNTABSZ])
{
	if (readfntab)
	{
		(*readfntab)[ehdrreadfnidx] = (readfn_t) ehdr32leread;
		(*readfntab)[shdrreadfnidx] = (readfn_t) shdr32leread;
		(*readfntab)[symreadfnidx] = (readfn_t) sym32leread;
		(*readfntab)[syminforeadfnidx] = (readfn_t) syminfo32leread;
		(*readfntab)[relreadfnidx] = (readfn_t) rel32leread;
		(*readfntab)[relareadfnidx] = (readfn_t) rela32leread;
		(*readfntab)[phdrreadfnidx] = (readfn_t) phdr32leread;
		(*readfntab)[dynreadfnidx] = (readfn_t) dyn32leread;
		(*readfntab)[verdefreadfnidx] = (readfn_t) verdef32leread;
		(*readfntab)[verdauxreadfnidx] = (readfn_t) verdaux32leread;
		(*readfntab)[verneedreadfnidx] = (readfn_t) verneed32leread;
		(*readfntab)[vernauxreadfnidx] = (readfn_t) vernaux32leread;
		(*readfntab)[nhdrreadfnidx] = (readfn_t) nhdr32leread;
		(*readfntab)[movereadfnidx] = (readfn_t) move32leread;
		(*readfntab)[libreadfnidx] = (readfn_t) lib32leread;
	}
}
