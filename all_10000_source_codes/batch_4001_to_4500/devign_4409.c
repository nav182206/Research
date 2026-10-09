/* 
 * Benchmark Sample ID : devign_4409
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void sp804_write(void *opaque, target_phys_addr_t offset,

                        uint64_t value, unsigned size)

{

    sp804_state *s = (sp804_state *)opaque;



    if (offset < 0x20) {

        arm_timer_write(s->timer[0], offset, value);

        return;

    }



    if (offset < 0x40) {

        arm_timer_write(s->timer[1], offset - 0x20, value);

        return;

    }



    /* Technically we could be writing to the Test Registers, but not likely */

    hw_error("%s: Bad offset %x\n", __func__, (int)offset);

}
