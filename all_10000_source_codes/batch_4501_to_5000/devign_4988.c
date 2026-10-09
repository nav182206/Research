/* 
 * Benchmark Sample ID : devign_4988
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d0d7708ba29cbcc343364a46bff981e0ff88366f
 */

void qemu_chr_free(CharDriverState *chr)

{

    if (chr->chr_close) {

        chr->chr_close(chr);

    }

    g_free(chr->filename);

    g_free(chr->label);

    qemu_opts_del(chr->opts);

    g_free(chr);

}
