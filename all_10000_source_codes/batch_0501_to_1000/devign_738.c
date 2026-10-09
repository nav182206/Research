/* 
 * Benchmark Sample ID : devign_738
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=db39fcf1f690b02d612e2bfc00980700887abe03
 */

static CharDriverState *qemu_chr_open_win_file(HANDLE fd_out)

{

    CharDriverState *chr;

    WinCharState *s;



    chr = g_malloc0(sizeof(CharDriverState));

    s = g_malloc0(sizeof(WinCharState));

    s->hcom = fd_out;

    chr->opaque = s;

    chr->chr_write = win_chr_write;

    return chr;

}
