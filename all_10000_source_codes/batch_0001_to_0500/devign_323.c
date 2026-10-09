/* 
 * Benchmark Sample ID : devign_323
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=871271615108fd58273423d98b7cefe08e6f75a0
 */

void monitor_flush(Monitor *mon)

{

    int i;

    if (term_outbuf_index > 0) {

        for (i = 0; i < MAX_MON; i++)

            if (monitor_hd[i] && monitor_hd[i]->focus == 0)

                qemu_chr_write(monitor_hd[i], term_outbuf, term_outbuf_index);

        term_outbuf_index = 0;

    }

}
