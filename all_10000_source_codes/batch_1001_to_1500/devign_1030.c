/* 
 * Benchmark Sample ID : devign_1030
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b9bec74bcb16519a876ec21cd5277c526a9b512d
 */

bool kvm_arch_stop_on_emulation_error(CPUState *env)

{

      return !(env->cr[0] & CR0_PE_MASK) ||

              ((env->segs[R_CS].selector  & 3) != 3);

}
