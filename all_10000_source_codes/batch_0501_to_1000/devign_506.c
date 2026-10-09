/* 
 * Benchmark Sample ID : devign_506
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ee71c984342408a357a74f65915bf66484ba445a
 */

static void icp_pit_write(void *opaque, target_phys_addr_t offset,

                          uint64_t value, unsigned size)

{

    icp_pit_state *s = (icp_pit_state *)opaque;

    int n;



    n = offset >> 8;

    if (n > 3) {

        hw_error("sp804_write: Bad timer %d\n", n);

    }



    arm_timer_write(s->timer[n], offset & 0xff, value);

}
