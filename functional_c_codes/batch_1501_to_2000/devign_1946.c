/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1946
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1f51470d044852592922f91000e741c381582cdc
 */

static int qemu_chr_open_win_pipe(QemuOpts *opts, CharDriverState **_chr)

{

    const char *filename = qemu_opt_get(opts, "path");

    CharDriverState *chr;

    WinCharState *s;



    chr = g_malloc0(sizeof(CharDriverState));

    s = g_malloc0(sizeof(WinCharState));

    chr->opaque = s;

    chr->chr_write = win_chr_write;

    chr->chr_close = win_chr_close;



    if (win_chr_pipe_init(chr, filename) < 0) {

        g_free(s);

        g_free(chr);

        return -EIO;

    }

    qemu_chr_generic_open(chr);



    *_chr = chr;

    return 0;

}
