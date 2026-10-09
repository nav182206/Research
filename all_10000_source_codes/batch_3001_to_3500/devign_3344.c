/* 
 * Benchmark Sample ID : devign_3344
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c5c752af8cddad3e4e51acef40a46db998638144
 */

static uint64_t hb_regs_read(void *opaque, hwaddr offset,

                             unsigned size)

{

    uint32_t *regs = opaque;

    uint32_t value = regs[offset/4];



    if ((offset == 0x100) || (offset == 0x108) || (offset == 0x10C)) {

        value |= 0x30000000;

    }



    return value;

}
