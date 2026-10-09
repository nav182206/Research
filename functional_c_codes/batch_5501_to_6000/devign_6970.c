/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6970
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9d4c0f4f0a71e74fd7e04d73620268484d693adf
 */

static sPAPRDREntitySense logical_entity_sense(sPAPRDRConnector *drc)

{

    if (drc->dev

        && (drc->allocation_state != SPAPR_DR_ALLOCATION_STATE_UNUSABLE)) {

        return SPAPR_DR_ENTITY_SENSE_PRESENT;

    } else {

        return SPAPR_DR_ENTITY_SENSE_UNUSABLE;

    }

}
