/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2749
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7983e829336f68b6df6952dd4b03493b1486fcf5
 */

static int write_console_data(SCLPEvent *event, const uint8_t *buf, int len)

{

    int ret = 0;

    const uint8_t *buf_offset;



    SCLPConsoleLM *scon = SCLPLM_CONSOLE(event);



    if (!scon->chr) {

        /* If there's no backend, we can just say we consumed all data. */

        return len;

    }



    buf_offset = buf;

    while (len > 0) {

        ret = qemu_chr_fe_write(scon->chr, buf, len);

        if (ret == 0) {

            /* a pty doesn't seem to be connected - no error */

            len = 0;

        } else if (ret == -EAGAIN || (ret > 0 && ret < len)) {

            len -= ret;

            buf_offset += ret;

        } else {

            len = 0;

        }

    }



    return ret;

}
