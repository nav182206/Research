/* 
 * Benchmark Sample ID : devign_7485
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b4db54132ffeadafa9516cc553ba9548e42d42ad
 */

static void close_htab_fd(sPAPRMachineState *spapr)

{

    if (spapr->htab_fd >= 0) {

        close(spapr->htab_fd);

    }

    spapr->htab_fd = -1;

}
