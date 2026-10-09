/* 
 * Benchmark Sample ID : devign_4896
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=91cda45b69e45a089f9989979a65db3f710c9925
 */

static int ppc_hash32_check_prot(int prot, int rw, int access_type)

{

    int ret;



    if (access_type == ACCESS_CODE) {

        if (prot & PAGE_EXEC) {

            ret = 0;

        } else {

            ret = -2;

        }

    } else if (rw) {

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
