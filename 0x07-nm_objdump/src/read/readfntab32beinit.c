#include "../read.h"

/**
 * readfntab32beinit - initialize an array of pointers to ELF reading functions
 *
 * @readfntab: pointer to the array to initialize
 */
void readfntab32beinit(readfn_t (*readfntab)[READFNTABSZ])
{
	if (readfntab)
	{
		(*readfntab)[ehdrreadfnidx] = (readfn_t) ehdr32beread;
		(*readfntab)[shdrreadfnidx] = (readfn_t) shdr32beread;
		(*readfntab)[symreadfnidx] = (readfn_t) sym32beread;
		(*readfntab)[syminforeadfnidx] = (readfn_t) syminfo32beread;
		(*readfntab)[relreadfnidx] = (readfn_t) rel32beread;
		(*readfntab)[relareadfnidx] = (readfn_t) rela32beread;
		(*readfntab)[phdrreadfnidx] = (readfn_t) phdr32beread;
		(*readfntab)[dynreadfnidx] = (readfn_t) dyn32beread;
		(*readfntab)[verdefreadfnidx] = (readfn_t) verdef32beread;
		(*readfntab)[verdauxreadfnidx] = (readfn_t) verdaux32beread;
		(*readfntab)[verneedreadfnidx] = (readfn_t) verneed32beread;
		(*readfntab)[vernauxreadfnidx] = (readfn_t) vernaux32beread;
		(*readfntab)[nhdrreadfnidx] = (readfn_t) nhdr32beread;
		(*readfntab)[movereadfnidx] = (readfn_t) move32beread;
		(*readfntab)[libreadfnidx] = (readfn_t) lib32beread;
	}
}
