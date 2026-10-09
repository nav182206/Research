/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2368
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e01b444523e2b0c663b42b3e8f44ef48a6153051
 */

static int ppc_hash32_pp_check(int key, int pp, int nx)

{

    int access;



    /* Compute access rights */

    access = 0;

    if (key == 0) {

        switch (pp) {

        case 0x0:

        case 0x1:

        case 0x2:

            access |= PAGE_WRITE;

            /* No break here */

        case 0x3:

            access |= PAGE_READ;

            break;

        }

    } else {

        switch (pp) {

        case 0x0:

            access = 0;

            break;

        case 0x1:

        case 0x3:

            access = PAGE_READ;

            break;

        case 0x2:

            access = PAGE_READ | PAGE_WRITE;

            break;

        }

    }

    if (nx == 0) {

        access |= PAGE_EXEC;

    }



    return access;

}
