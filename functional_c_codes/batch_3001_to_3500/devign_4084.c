/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4084
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t mv88w8618_pic_read(void *opaque, target_phys_addr_t offset,

                                   unsigned size)

{

    mv88w8618_pic_state *s = opaque;



    switch (offset) {

    case MP_PIC_STATUS:

        return s->level & s->enabled;



    default:

        return 0;

    }

}
