/* 
 * Benchmark Sample ID : devign_2080
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0dfabd39d523fc3f6f0f8c441f41c013cc429b52
 */

static uint32_t rtas_set_isolation_state(uint32_t idx, uint32_t state)

{

    sPAPRDRConnector *drc = spapr_drc_by_index(idx);

    sPAPRDRConnectorClass *drck;



    if (!drc) {

        return RTAS_OUT_PARAM_ERROR;

    }



    drck = SPAPR_DR_CONNECTOR_GET_CLASS(drc);

    return drck->set_isolation_state(drc, state);

}
