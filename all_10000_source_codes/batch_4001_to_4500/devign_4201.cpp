/* 
 * Benchmark Sample ID : devign_4201
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4445b1d27ee65ceee12b71bc20242996c8eb5cf8
 */

void spapr_drc_reset(sPAPRDRConnector *drc)

{

    sPAPRDRConnectorClass *drck = SPAPR_DR_CONNECTOR_GET_CLASS(drc);



    trace_spapr_drc_reset(spapr_drc_index(drc));



    g_free(drc->ccs);

    drc->ccs = NULL;



    /* immediately upon reset we can safely assume DRCs whose devices

     * are pending removal can be safely removed.

     */

    if (drc->unplug_requested) {

        spapr_drc_release(drc);

    }



    if (drc->dev) {

        /* A device present at reset is ready to go, same as coldplugged */

        drc->state = drck->ready_state;

    } else {

        drc->state = drck->empty_state;

    }

}
