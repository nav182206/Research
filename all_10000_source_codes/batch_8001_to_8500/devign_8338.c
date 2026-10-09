/* 
 * Benchmark Sample ID : devign_8338
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e01b444523e2b0c663b42b3e8f44ef48a6153051
 */

static int ppc_hash64_check_prot(int prot, int rwx)

{

    int ret;



    if (rwx == 2) {

        if (prot & PAGE_EXEC) {

            ret = 0;

        } else {

            ret = -2;

        }

    } else if (rwx == 1) {

        if (prot & PAGE_WRITE) {

            ret = 0;

        } else {

            ret = -2;

        }

    } else {

        if (prot & PAGE_READ) {

            ret = 0;

        } else {

            ret = -2;

        }

    }



    return ret;

}
