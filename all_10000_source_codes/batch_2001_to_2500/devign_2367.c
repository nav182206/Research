/* 
 * Benchmark Sample ID : devign_2367
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9307c4c1d93939db9b04117b654253af5113dc21
 */

static void do_commit(int argc, const char **argv)

{

    int i;



    for (i = 0; i < MAX_DISKS; i++) {

        if (bs_table[i])

            bdrv_commit(bs_table[i]);

    }

}
