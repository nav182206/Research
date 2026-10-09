/* 
 * Benchmark Sample ID : devign_5869
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=94a40fc56036b5058b0b194d9e372a22e65ce7be
 */

static void qemu_chr_free_common(CharDriverState *chr)

{




    g_free(chr->filename);

    g_free(chr->label);

    if (chr->logfd != -1) {

        close(chr->logfd);


    qemu_mutex_destroy(&chr->chr_write_lock);

    g_free(chr);
