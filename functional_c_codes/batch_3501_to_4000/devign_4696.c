/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4696
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d0d7708ba29cbcc343364a46bff981e0ff88366f
 */

static CharDriverState *qemu_chr_open_win_path(const char *filename,

                                               Error **errp)

{

    CharDriverState *chr;

    WinCharState *s;



    chr = qemu_chr_alloc();

    s = g_new0(WinCharState, 1);

    chr->opaque = s;

    chr->chr_write = win_chr_write;

    chr->chr_close = win_chr_close;



    if (win_chr_init(chr, filename, errp) < 0) {

        g_free(s);

        g_free(chr);

        return NULL;

    }

    return chr;

}
