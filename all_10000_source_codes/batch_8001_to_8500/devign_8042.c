/* 
 * Benchmark Sample ID : devign_8042
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=245f7b51c0ea04fb2224b1127430a096c91aee70
 */

static void vnc_zlib_start(VncState *vs)

{

    buffer_reset(&vs->zlib);



    // make the output buffer be the zlib buffer, so we can compress it later

    vs->zlib_tmp = vs->output;

    vs->output = vs->zlib;

}
