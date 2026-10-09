/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_626
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c9f82d013be0d8d9c5d9f51bb76e337a0a5a5cac
 */

void helper_dcbz(CPUPPCState *env, target_ulong addr, uint32_t is_dcbzl)

{

    int dcbz_size = env->dcache_line_size;



#if defined(TARGET_PPC64)

    if (!is_dcbzl &&

        (env->excp_model == POWERPC_EXCP_970) &&

        ((env->spr[SPR_970_HID5] >> 7) & 0x3) == 1) {

        dcbz_size = 32;

    }

#endif



    /* XXX add e500mc support */



    do_dcbz(env, addr, dcbz_size, GETPC());

}
