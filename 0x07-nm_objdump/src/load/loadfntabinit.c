#include "../load.h"

/**
 * loadfntabinit32le - initialize an array of pointers to ELF loading functions
 *
 * @loadfntab: pointer to the array to initialize
 */
void loadfntabinit32le(loadfn_t (*loadfntab)[LOADFNTABSIZE])
{
	if (loadfntab)
	{
		(*loadfntab)[ehdrloadfntabidx] = (loadfn_t) ehdr32leload;
		(*loadfntab)[shdrloadfntabidx] = (loadfn_t) shdr32leload;
		(*loadfntab)[symloadfntabidx] = (loadfn_t) sym32leload;
		(*loadfntab)[syminfoloadfntabidx] = (loadfn_t) syminfo32leload;
		(*loadfntab)[relloadfntabidx] = (loadfn_t) rel32leload;
		(*loadfntab)[relaloadfntabidx] = (loadfn_t) rela32leload;
		(*loadfntab)[phdrloadfntabidx] = (loadfn_t) phdr32leload;
		(*loadfntab)[dynloadfntabidx] = (loadfn_t) dyn32leload;
		(*loadfntab)[verdefloadfntabidx] = (loadfn_t) verdef32leload;
		(*loadfntab)[verdauxloadfntabidx] = (loadfn_t) verdaux32leload;
		(*loadfntab)[verneedloadfntabidx] = (loadfn_t) verneed32leload;
		(*loadfntab)[vernauxloadfntabidx] = (loadfn_t) vernaux32leload;
		(*loadfntab)[nhdrloadfntabidx] = (loadfn_t) nhdr32leload;
		(*loadfntab)[moveloadfntabidx] = (loadfn_t) move32leload;
		(*loadfntab)[libloadfntabidx] = (loadfn_t) lib32leload;
	}
}

/**
 * loadfntabinit32be - initialize an array of pointers to ELF loading functions
 *
 * @loadfntab: pointer to the array to initialize
 */
void loadfntabinit32be(loadfn_t (*loadfntab)[LOADFNTABSIZE])
{
	if (loadfntab)
	{
		(*loadfntab)[ehdrloadfntabidx] = (loadfn_t) ehdr32beload;
		(*loadfntab)[shdrloadfntabidx] = (loadfn_t) shdr32beload;
		(*loadfntab)[symloadfntabidx] = (loadfn_t) sym32beload;
		(*loadfntab)[syminfoloadfntabidx] = (loadfn_t) syminfo32beload;
		(*loadfntab)[relloadfntabidx] = (loadfn_t) rel32beload;
		(*loadfntab)[relaloadfntabidx] = (loadfn_t) rela32beload;
		(*loadfntab)[phdrloadfntabidx] = (loadfn_t) phdr32beload;
		(*loadfntab)[dynloadfntabidx] = (loadfn_t) dyn32beload;
		(*loadfntab)[verdefloadfntabidx] = (loadfn_t) verdef32beload;
		(*loadfntab)[verdauxloadfntabidx] = (loadfn_t) verdaux32beload;
		(*loadfntab)[verneedloadfntabidx] = (loadfn_t) verneed32beload;
		(*loadfntab)[vernauxloadfntabidx] = (loadfn_t) vernaux32beload;
		(*loadfntab)[nhdrloadfntabidx] = (loadfn_t) nhdr32beload;
		(*loadfntab)[moveloadfntabidx] = (loadfn_t) move32beload;
		(*loadfntab)[libloadfntabidx] = (loadfn_t) lib32beload;
	}
}

/**
 * loadfntabinit64le - initialize an array of pointers to ELF loading functions
 *
 * @loadfntab: pointer to the array to initialize
 */
void loadfntabinit64le(loadfn_t (*loadfntab)[LOADFNTABSIZE])
{
	if (loadfntab)
	{
		(*loadfntab)[ehdrloadfntabidx] = (loadfn_t) ehdr64leload;
		(*loadfntab)[shdrloadfntabidx] = (loadfn_t) shdr64leload;
		(*loadfntab)[symloadfntabidx] = (loadfn_t) sym64leload;
		(*loadfntab)[syminfoloadfntabidx] = (loadfn_t) syminfo64leload;
		(*loadfntab)[relloadfntabidx] = (loadfn_t) rel64leload;
		(*loadfntab)[relaloadfntabidx] = (loadfn_t) rela64leload;
		(*loadfntab)[phdrloadfntabidx] = (loadfn_t) phdr64leload;
		(*loadfntab)[dynloadfntabidx] = (loadfn_t) dyn64leload;
		(*loadfntab)[verdefloadfntabidx] = (loadfn_t) verdef64leload;
		(*loadfntab)[verdauxloadfntabidx] = (loadfn_t) verdaux64leload;
		(*loadfntab)[verneedloadfntabidx] = (loadfn_t) verneed64leload;
		(*loadfntab)[vernauxloadfntabidx] = (loadfn_t) vernaux64leload;
		(*loadfntab)[nhdrloadfntabidx] = (loadfn_t) nhdr64leload;
		(*loadfntab)[moveloadfntabidx] = (loadfn_t) move64leload;
		(*loadfntab)[libloadfntabidx] = (loadfn_t) lib64leload;
	}
}

/**
 * loadfntabinit64be - initialize an array of pointers to ELF loading functions
 *
 * @loadfntab: pointer to the array to initialize
 */
void loadfntabinit64be(loadfn_t (*loadfntab)[LOADFNTABSIZE])
{
	if (loadfntab)
	{
		(*loadfntab)[ehdrloadfntabidx] = (loadfn_t) ehdr64beload;
		(*loadfntab)[shdrloadfntabidx] = (loadfn_t) shdr64beload;
		(*loadfntab)[symloadfntabidx] = (loadfn_t) sym64beload;
		(*loadfntab)[syminfoloadfntabidx] = (loadfn_t) syminfo64beload;
		(*loadfntab)[relloadfntabidx] = (loadfn_t) rel64beload;
		(*loadfntab)[relaloadfntabidx] = (loadfn_t) rela64beload;
		(*loadfntab)[phdrloadfntabidx] = (loadfn_t) phdr64beload;
		(*loadfntab)[dynloadfntabidx] = (loadfn_t) dyn64beload;
		(*loadfntab)[verdefloadfntabidx] = (loadfn_t) verdef64beload;
		(*loadfntab)[verdauxloadfntabidx] = (loadfn_t) verdaux64beload;
		(*loadfntab)[verneedloadfntabidx] = (loadfn_t) verneed64beload;
		(*loadfntab)[vernauxloadfntabidx] = (loadfn_t) vernaux64beload;
		(*loadfntab)[nhdrloadfntabidx] = (loadfn_t) nhdr64beload;
		(*loadfntab)[moveloadfntabidx] = (loadfn_t) move64beload;
		(*loadfntab)[libloadfntabidx] = (loadfn_t) lib64beload;
	}
}
