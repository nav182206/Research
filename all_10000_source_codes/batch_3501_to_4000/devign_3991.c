/* 
 * Benchmark Sample ID : devign_3991
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=621ff94d5074d88253a5818c6b9c4db718fbfc65
 */

static void check_suspend_mode(GuestSuspendMode mode, Error **errp)

{

    SYSTEM_POWER_CAPABILITIES sys_pwr_caps;

    Error *local_err = NULL;



    ZeroMemory(&sys_pwr_caps, sizeof(sys_pwr_caps));

    if (!GetPwrCapabilities(&sys_pwr_caps)) {

        error_setg(&local_err, QERR_QGA_COMMAND_FAILED,

                   "failed to determine guest suspend capabilities");

        goto out;

    }



    switch (mode) {

    case GUEST_SUSPEND_MODE_DISK:

        if (!sys_pwr_caps.SystemS4) {

            error_setg(&local_err, QERR_QGA_COMMAND_FAILED,

                       "suspend-to-disk not supported by OS");

        }

        break;

    case GUEST_SUSPEND_MODE_RAM:

        if (!sys_pwr_caps.SystemS3) {

            error_setg(&local_err, QERR_QGA_COMMAND_FAILED,

                       "suspend-to-ram not supported by OS");

        }

        break;

    default:

        error_setg(&local_err, QERR_INVALID_PARAMETER_VALUE, "mode",

                   "GuestSuspendMode");

    }



out:

    if (local_err) {

        error_propagate(errp, local_err);

    }

}
