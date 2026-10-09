/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6797
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=056f49ff2cf645dc484956b00b65a3aa18a1a9a3
 */

void monitor_flush(Monitor *mon)

{

    int rc;

    size_t len;

    const char *buf;



    if (mon->skip_flush) {

        return;

    }



    buf = qstring_get_str(mon->outbuf);

    len = qstring_get_length(mon->outbuf);



    if (len && !mon->mux_out) {

        rc = qemu_chr_fe_write(mon->chr, (const uint8_t *) buf, len);

        if (rc == len) {

            /* all flushed */

            QDECREF(mon->outbuf);

            mon->outbuf = qstring_new();

            return;

        }

        if (rc > 0) {

            /* partinal write */

            QString *tmp = qstring_from_str(buf + rc);

            QDECREF(mon->outbuf);

            mon->outbuf = tmp;

        }

        if (mon->watch == 0) {

            mon->watch = qemu_chr_fe_add_watch(mon->chr, G_IO_OUT,

                                               monitor_unblocked, mon);

        }

    }

}
