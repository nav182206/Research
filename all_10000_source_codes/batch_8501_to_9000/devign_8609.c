/* 
 * Benchmark Sample ID : devign_8609
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t mv88w8618_flashcfg_read(void *opaque,

                                        target_phys_addr_t offset,

                                        unsigned size)

{

    mv88w8618_flashcfg_state *s = opaque;



    switch (offset) {

    case MP_FLASHCFG_CFGR0:

        return s->cfgr0;



    default:

        return 0;

    }

}
