#include "../read.h"

/**
 * readfntab64beinit - initialize an array of pointers to ELF reading functions
 *
 * @readfntab: pointer to the array to initialize
 */
void readfntab64beinit(readfn_t (*readfntab)[READFNTABSZ])
{
	if (readfntab)
	{
		(*readfntab)[ehdrreadfnidx] = (readfn_t) ehdr64beread;
		(*readfntab)[shdrreadfnidx] = (readfn_t) shdr64beread;
		(*readfntab)[symreadfnidx] = (readfn_t) sym64beread;
		(*readfntab)[syminforeadfnidx] = (readfn_t) syminfo64beread;
		(*readfntab)[relreadfnidx] = (readfn_t) rel64beread;
		(*readfntab)[relareadfnidx] = (readfn_t) rela64beread;
		(*readfntab)[phdrreadfnidx] = (readfn_t) phdr64beread;
		(*readfntab)[dynreadfnidx] = (readfn_t) dyn64beread;
		(*readfntab)[verdefreadfnidx] = (readfn_t) verdef64beread;
		(*readfntab)[verdauxreadfnidx] = (readfn_t) verdaux64beread;
		(*readfntab)[verneedreadfnidx] = (readfn_t) verneed64beread;
		(*readfntab)[vernauxreadfnidx] = (readfn_t) vernaux64beread;
		(*readfntab)[nhdrreadfnidx] = (readfn_t) nhdr64beread;
		(*readfntab)[movereadfnidx] = (readfn_t) move64beread;
		(*readfntab)[libreadfnidx] = (readfn_t) lib64beread;
	}
}
