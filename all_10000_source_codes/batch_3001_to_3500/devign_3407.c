/* 
 * Benchmark Sample ID : devign_3407
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ee9a569ab88edd0755402aaf31ec0c69decf7756
 */

static void rtas_set_tce_bypass(PowerPCCPU *cpu, sPAPREnvironment *spapr,

                                uint32_t token,

                                uint32_t nargs, target_ulong args,

                                uint32_t nret, target_ulong rets)

{

    VIOsPAPRBus *bus = spapr->vio_bus;

    VIOsPAPRDevice *dev;

    uint32_t unit, enable;



    if (nargs != 2) {

        rtas_st(rets, 0, RTAS_OUT_PARAM_ERROR);

        return;

    }

    unit = rtas_ld(args, 0);

    enable = rtas_ld(args, 1);

    dev = spapr_vio_find_by_reg(bus, unit);

    if (!dev) {

        rtas_st(rets, 0, RTAS_OUT_PARAM_ERROR);

        return;

    }



    if (!dev->tcet) {

        rtas_st(rets, 0, RTAS_OUT_PARAM_ERROR);

        return;

    }



    spapr_tce_set_bypass(dev->tcet, !!enable);



    rtas_st(rets, 0, RTAS_OUT_SUCCESS);

}
