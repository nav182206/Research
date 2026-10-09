/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5021
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=68931a4082812f56657b39168e815c48f0ab0a8c
 */

static void xtensa_lx60_init(MachineState *machine)

{

    static const LxBoardDesc lx60_board = {

        .flash_base = 0xf8000000,

        .flash_size = 0x00400000,

        .flash_sector_size = 0x10000,

        .sram_size = 0x20000,

    };

    lx_init(&lx60_board, machine);

}
