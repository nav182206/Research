/* 
 * Benchmark Sample ID : devign_4410
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static void cmd_start_stop_unit(IDEState *s, uint8_t* buf)

{

    int sense;

    bool start = buf[4] & 1;

    bool loej = buf[4] & 2;     /* load on start, eject on !start */

    int pwrcnd = buf[4] & 0xf0;



    if (pwrcnd) {

        /* eject/load only happens for power condition == 0 */

        return;

    }



    if (loej) {

        if (!start && !s->tray_open && s->tray_locked) {

            sense = bdrv_is_inserted(s->bs)

                ? NOT_READY : ILLEGAL_REQUEST;

            ide_atapi_cmd_error(s, sense, ASC_MEDIA_REMOVAL_PREVENTED);

            return;

        }



        if (s->tray_open != !start) {

            bdrv_eject(s->bs, !start);

            s->tray_open = !start;

        }

    }



    ide_atapi_cmd_ok(s);

}
