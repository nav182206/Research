/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_798
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

void qemu_chr_info(Monitor *mon)

{

    CharDriverState *chr;



    TAILQ_FOREACH(chr, &chardevs, next) {

        monitor_printf(mon, "%s: filename=%s\n", chr->label, chr->filename);

    }

}
