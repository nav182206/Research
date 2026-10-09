/* 
 * Benchmark Sample ID : devign_1627
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d0d7708ba29cbcc343364a46bff981e0ff88366f
 */

static CharDriverState *qemu_chr_open_win_con(const char *id,

                                              ChardevBackend *backend,

                                              ChardevReturn *ret,

                                              Error **errp)

{

    return qemu_chr_open_win_file(GetStdHandle(STD_OUTPUT_HANDLE));

}
