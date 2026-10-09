/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_695
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0280b3eb7c0519b43452c05cf51f8777d9e38975
 */

static bool gscb_needed(void *opaque)

{

    return kvm_s390_get_gs();

}
