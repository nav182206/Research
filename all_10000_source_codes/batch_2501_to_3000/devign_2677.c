/* 
 * Benchmark Sample ID : devign_2677
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5fb6c7a8b26eab1a22207d24b4784bd2b39ab54b
 */

static void vnc_client_error(VncState *vs)

{

    vnc_client_io_error(vs, -1, EINVAL);

}
