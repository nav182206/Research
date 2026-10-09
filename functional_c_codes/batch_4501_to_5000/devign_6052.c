/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6052
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3e305e4a4752f70c0b5c3cf5b43ec957881714f7
 */

static void vnc_debug_gnutls_log(int level, const char* str) {

    VNC_DEBUG("%d %s", level, str);

}
