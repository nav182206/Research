/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5890
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=da1fcfda59a6bcbdf58d49243fbced455f2bf78a
 */

void net_set_boot_mask(int net_boot_mask)

{

    int i;



    /* Only the first four NICs may be bootable */

    net_boot_mask = net_boot_mask & 0xF;



    for (i = 0; i < nb_nics; i++) {

        if (net_boot_mask & (1 << i)) {

            net_boot_mask &= ~(1 << i);

        }

    }



    if (net_boot_mask) {

        fprintf(stderr, "Cannot boot from non-existent NIC\n");

        exit(1);

    }

}
