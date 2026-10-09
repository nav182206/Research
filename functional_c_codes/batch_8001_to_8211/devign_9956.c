/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9956
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6ab3fc32ea640026726bc5f9f4db622d0954fb8a
 */

static ssize_t write_console_data(SCLPEvent *event, const uint8_t *buf,

                                  size_t len)

{

    SCLPConsole *scon = SCLP_CONSOLE(event);



    if (!scon->chr) {

        /* If there's no backend, we can just say we consumed all data. */

        return len;

    }





    return qemu_chr_fe_write_all(scon->chr, buf, len);

}
