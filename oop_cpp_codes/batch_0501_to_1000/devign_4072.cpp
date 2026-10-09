/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_4072
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8b7f6fbbdc5545f749864fdf295f2fae14c7ef0a
 */

void hmp_cont(Monitor *mon, const QDict *qdict)

{

    Error *errp = NULL;



    qmp_cont(&errp);

    if (error_is_set(&errp)) {

        if (error_is_type(errp, QERR_DEVICE_ENCRYPTED)) {

            const char *device;



            /* The device is encrypted. Ask the user for the password

               and retry */



            device = error_get_field(errp, "device");

            assert(device != NULL);



            monitor_read_block_device_key(mon, device, hmp_cont_cb, mon);

            error_free(errp);

            return;

        }

        hmp_handle_error(mon, &errp);

    }

}
