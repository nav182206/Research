/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6584
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1f51470d044852592922f91000e741c381582cdc
 */

static int qemu_chr_open_win_file(HANDLE fd_out, CharDriverState **pchr)

{

    CharDriverState *chr;

    WinCharState *s;



    chr = g_malloc0(sizeof(CharDriverState));

    s = g_malloc0(sizeof(WinCharState));

    s->hcom = fd_out;

    chr->opaque = s;

    chr->chr_write = win_chr_write;

    qemu_chr_generic_open(chr);

    *pchr = chr;

    return 0;

}
