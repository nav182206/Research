/* 
 * Benchmark Sample ID : devign_3615
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7f61f4690dd153be98900a2a508b88989e692753
 */

pvscsi_on_cmd_setup_rings(PVSCSIState *s)

{

    PVSCSICmdDescSetupRings *rc =

        (PVSCSICmdDescSetupRings *) s->curr_cmd_data;



    trace_pvscsi_on_cmd_arrived("PVSCSI_CMD_SETUP_RINGS");



    pvscsi_dbg_dump_tx_rings_config(rc);

    if (pvscsi_ring_init_data(&s->rings, rc) < 0) {

        return PVSCSI_COMMAND_PROCESSING_FAILED;

    }



    s->rings_info_valid = TRUE;

    return PVSCSI_COMMAND_PROCESSING_SUCCEEDED;

}
