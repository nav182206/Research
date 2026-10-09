/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4747
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=67fea71bf3be579ad0be5abe34cd6fa1bc65ad5b
 */

static uint32_t rtas_set_dr_indicator(uint32_t idx, uint32_t state)

{

    sPAPRDRConnector *drc = spapr_drc_by_index(idx);



    if (!drc) {

        return RTAS_OUT_PARAM_ERROR;

    }



    trace_spapr_drc_set_dr_indicator(idx, state);

    drc->dr_indicator = state;

    return RTAS_OUT_SUCCESS;

}
