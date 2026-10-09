/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5315
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=210b580b106fa798149e28aa13c66b325a43204e
 */

static void rtas_system_reboot(sPAPREnvironment *spapr,

                               uint32_t token, uint32_t nargs,

                               target_ulong args,

                               uint32_t nret, target_ulong rets)

{

    if (nargs != 0 || nret != 1) {

        rtas_st(rets, 0, -3);

        return;

    }

    qemu_system_reset_request();

    rtas_st(rets, 0, 0);

}
