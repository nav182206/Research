/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8606
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=506590836144af7d0de3fc4c691bb5ed49d41645
 */

static void ppc_hash64_set_dsi(CPUState *cs, CPUPPCState *env, uint64_t dar,

                               uint64_t dsisr)

{

    bool vpm;



    if (msr_dr) {

        vpm = !!(env->spr[SPR_LPCR] & LPCR_VPM1);

    } else {

        vpm = !!(env->spr[SPR_LPCR] & LPCR_VPM0);

    }

    if (vpm && !msr_hv) {

        cs->exception_index = POWERPC_EXCP_HDSI;

        env->spr[SPR_HDAR] = dar;

        env->spr[SPR_HDSISR] = dsisr;

    } else {

        cs->exception_index = POWERPC_EXCP_DSI;

        env->spr[SPR_DAR] = dar;

        env->spr[SPR_DSISR] = dsisr;

   }

    env->error_code = 0;

}
