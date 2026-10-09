/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4360
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=10a412dab3f54439ea3d60274eb41668f7d83bd2
 */

static void sd_set_status(SDState *sd)

{

    switch (sd->state) {

    case sd_inactive_state:

        sd->mode = sd_inactive;

        break;



    case sd_idle_state:

    case sd_ready_state:

    case sd_identification_state:

        sd->mode = sd_card_identification_mode;

        break;



    case sd_standby_state:

    case sd_transfer_state:

    case sd_sendingdata_state:

    case sd_receivingdata_state:

    case sd_programming_state:

    case sd_disconnect_state:

        sd->mode = sd_data_transfer_mode;

        break;

    }



    sd->card_status &= ~CURRENT_STATE;

    sd->card_status |= sd->state << 9;

}
