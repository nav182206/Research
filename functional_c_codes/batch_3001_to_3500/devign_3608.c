/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3608
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bd5c51ee6c4f1c79cae5ad2516d711a27b4ea8ec
 */

static CharDriverState *qemu_chr_open_win_path(const char *filename)

{

    CharDriverState *chr;

    WinCharState *s;



    chr = g_malloc0(sizeof(CharDriverState));

    s = g_malloc0(sizeof(WinCharState));

    chr->opaque = s;

    chr->chr_write = win_chr_write;

    chr->chr_close = win_chr_close;



    if (win_chr_init(chr, filename) < 0) {

        g_free(s);

        g_free(chr);

        return NULL;

    }

    qemu_chr_be_generic_open(chr);

    return chr;

}
