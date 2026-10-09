/* 
 * Benchmark Sample ID : devign_6676
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4cc2cc085586cdb787a24d78a7ba032fa657275a
 */

target_ulong helper_load_slb_vsid(CPUPPCState *env, target_ulong rb)

{

    target_ulong rt;



    if (ppc_load_slb_vsid(env, rb, &rt) < 0) {

        helper_raise_exception_err(env, POWERPC_EXCP_PROGRAM,

                                   POWERPC_EXCP_INVAL);

    }

    return rt;

}
