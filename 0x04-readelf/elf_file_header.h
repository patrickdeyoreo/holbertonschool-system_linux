#ifndef _ELF_FILE_HEADER_H_
#define _ELF_FILE_HEADER_H_

#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define E_MACHINE_TABLE {					\
	"No machine",						\
	"AT&T WE 32100",					\
	"Sparc",						\
	"Intel 80386",						\
	"Motorola m68k family",					\
	"Motorola m88k family",					\
	"Intel MCU",						\
	"Intel 80860",						\
	"MIPS R3000 big-endian",				\
	"IBM System/370",					\
	"MIPS R3000 little-endian",				\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	"HPPA",							\
	NULL,							\
	"Fujitsu VPP500",					\
	"Sun's \"v8plus\"",					\
	"Intel 80960",						\
	"PowerPC",						\
	"PowerPC 64-bit",					\
	"IBM S390",						\
	"IBM SPU/SPC",						\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	"NEC V800 series",					\
	"Fujitsu FR20",						\
	"TRW RH-32",						\
	"Motorola RCE",						\
	"ARM",							\
	"Digital Alpha",					\
	"Hitachi SH",						\
	"SPARC v9 64-bit",					\
	"Siemens Tricore",					\
	"Argonaut RISC Core",					\
	"Hitachi H8/300",					\
	"Hitachi H8/300H",					\
	"Hitachi H8S",						\
	"Hitachi H8/500",					\
	"Intel Merced",						\
	"Stanford MIPS-X",					\
	"Motorola Coldfire",					\
	"Motorola M68HC12",					\
	"Fujitsu MMA Multimedia Accelerator",			\
	"Siemens PCP",						\
	"Sony nCPU embeeded RISC",				\
	"Denso NDR1 microprocessor",				\
	"Motorola Start*Core processor",			\
	"Toyota ME16 processor",				\
	"STMicroelectronic ST100 processor",			\
	"Advanced Logic Corp. Tinyj emb.fam",			\
	"Advanced Micro Devices X86-64",			\
	"Sony DSP Processor",					\
	"Digital PDP-10",					\
	"Digital PDP-11",					\
	"Siemens FX66 microcontroller",				\
	"STMicroelectronics ST9+ 8/16 mc",			\
	"STmicroelectronics ST7 8 bit mc",			\
	"Motorola MC68HC16 microcontroller",			\
	"Motorola MC68HC11 microcontroller",			\
	"Motorola MC68HC08 microcontroller",			\
	"Motorola MC68HC05 microcontroller",			\
	"Silicon Graphics SVx",					\
	"STMicroelectronics ST19 8 bit mc",			\
	"Digital VAX",						\
	"Axis Communications 32-bit emb.proc",			\
	"Infineon Technologies 32-bit emb.proc",		\
	"Element 14 64-bit DSP Processor",			\
	"LSI Logic 16-bit DSP Processor",			\
	"Donald Knuth's educational 64-bit proc",		\
	"Harvard University machine-independent object files",	\
	"SiTera Prism",						\
	"Atmel AVR 8-bit microcontroller",			\
	"Fujitsu FR30",						\
	"Mitsubishi D10V",					\
	"Mitsubishi D30V",					\
	"NEC v850",						\
	"Mitsubishi M32R",					\
	"Matsushita MN10300",					\
	"Matsushita MN10200",					\
	"picoJava",						\
	"OpenRISC 32-bit embedded processor",			\
	"ARC International ARCompact",				\
	"Tensilica Xtensa Architecture",			\
	"Alphamosaic VideoCore",				\
	"Thompson Multimedia General Purpose Proc",		\
	"National Semi. 32000",					\
	"Tenor Network TPC",					\
	"Trebia SNP 1000",					\
	"STMicroelectronics ST200",				\
	"Ubicom IP2xxx",					\
	"MAX processor",					\
	"National Semi. CompactRISC",				\
	"Fujitsu F2MC16",					\
	"Texas Instruments msp430",				\
	"Analog Devices Blackfin DSP",				\
	"Seiko Epson S1C33 family",				\
	"Sharp embedded microprocessor",			\
	"Arca RISC",						\
	"PKU-Unity & MPRC Peking Uni. mc series",		\
	"eXcess configurable cpu",				\
	"Icera Semi. Deep Execution Processor",			\
	"Altera Nios II",					\
	"National Semi. CompactRISC CRX",			\
	"Motorola XGATE",					\
	"Infineon C16x/XC16x",					\
	"Renesas M16C",						\
	"Microchip Technology dsPIC30F",			\
	"Freescale Communication Engine RISC",			\
	"Renesas M32C",						\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	"Altium TSK3000",					\
	"Freescale RS08",					\
	"Analog Devices SHARC family",				\
	"Cyan Technology eCOG2",				\
	"Sunplus S+core7 RISC",					\
	"New Japan Radio (NJR) 24-bit DSP",			\
	"Broadcom VideoCore III",				\
	"RISC for Lattice FPGA",				\
	"Seiko Epson C17",					\
	"Texas Instruments TMS320C6000 DSP",			\
	"Texas Instruments TMS320C2000 DSP",			\
	"Texas Instruments TMS320C55x DSP",			\
	"Texas Instruments App. Specific RISC",			\
	"Texas Instruments Prog. Realtime Unit",		\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	"STMicroelectronics 64bit VLIW DSP",			\
	"Cypress M8C",						\
	"Renesas R32C",						\
	"NXP Semi. TriMedia",					\
	"QUALCOMM DSP6",					\
	"Intel 8051 and variants",				\
	"STMicroelectronics STxP7x",				\
	"Andes Tech. compact code emb. RISC",			\
	"Cyan Technology eCOG1X",				\
	"Dallas Semi. MAXQ30 mc",				\
	"New Japan Radio (NJR) 16-bit DSP",			\
	"M2000 Reconfigurable RISC",				\
	"Cray NV2 vector architecture",				\
	"Renesas RX",						\
	"Imagination Tech. META",				\
	"MCST Elbrus",						\
	"Cyan Technology eCOG16",				\
	"National Semi. CompactRISC CR16",			\
	"Freescale Extended Time Processing Unit",		\
	"Infineon Tech. SLE9X",					\
	"Intel L10M",						\
	"Intel K10M",						\
	NULL,							\
	"ARM AARCH64",						\
	NULL,							\
	"Amtel 32-bit microprocessor",				\
	"STMicroelectronics STM8",				\
	"Tileta TILE64",					\
	"Tilera TILEPro",					\
	"Xilinx MicroBlaze",					\
	"NVIDIA CUDA",						\
	"Tilera TILE-Gx",					\
	"CloudShield",						\
	"KIPO-KAIST Core-A 1st gen.",				\
	"KIPO-KAIST Core-A 2nd gen.",				\
	"Synopsys ARCompact V2",				\
	"Open8 RISC",						\
	"Renesas RL78",						\
	"Broadcom VideoCore V",					\
	"Renesas 78KOR",					\
	"Freescale 56800EX DSC",				\
	"Beyond BA1",						\
	"Beyond BA2",						\
	"XMOS xCORE",						\
	"Microchip 8-bit PIC(r)",				\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	"KM211 KM32",						\
	"KM211 KMX32",						\
	"KM211 KMX16",						\
	"KM211 KMX8",						\
	"KM211 KVARC",						\
	"Paneve CDP",						\
	"Cognitive Smart Memory Processor",			\
	"Bluechip CoolEngine",					\
	"Nanoradio Optimized RISC",				\
	"CSR Kalimba",						\
	"Zilog Z80",						\
	"Controls and Data Services VISIUMcore",		\
	"FTDI Chip FT32",					\
	"Moxie processor",					\
	"AMD GPU",						\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	NULL,							\
	"RISC-V",						\
	NULL,							\
	NULL,							\
	NULL,							\
	"Linux BPF -- in-kernel virtual machine"		\
}

void elf_ident(unsigned char (*e_ident)[EI_NIDENT]);
void elf_magic(unsigned char (*e_ident)[EI_NIDENT]);
void elf_class(unsigned char (*e_ident)[EI_NIDENT]);
void elf_data(unsigned char (*e_ident)[EI_NIDENT]);
void elf_ev(unsigned char (*e_ident)[EI_NIDENT]);
void elf_osabi(unsigned char (*e_ident)[EI_NIDENT]);
void elf_abivers(unsigned char (*e_ident)[EI_NIDENT]);
void elf_type(Elf64_Half e_type);
void elf_machine(Elf64_Half e_machine);
void elf_version(Elf64_Word e_version);
void elf_entry(Elf64_Addr e_entry);
void elf_phoff(Elf64_Off e_phoff);
void elf_shoff(Elf64_Off e_shoff);
void elf_flags(Elf64_Word e_flags);
void elf_ehsize(Elf64_Half e_ehsize);
void elf_phentsize(Elf64_Half e_phentsize);
void elf_phnum(Elf64_Half e_phnum);
void elf_shentsize(Elf64_Half e_shentsize);
void elf_shnum(Elf64_Half e_shnum);
void elf_shstrndx(Elf64_Half e_shstrndx);

#endif /* _ELF_FILE_HEADER_H_ */
