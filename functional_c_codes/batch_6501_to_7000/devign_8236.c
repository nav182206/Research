/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8236
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=28143b409f698210d85165ca518235ac7e7c5ac5
 */

int kvm_has_xsave(void)

{

    return kvm_state->xsave;

}
