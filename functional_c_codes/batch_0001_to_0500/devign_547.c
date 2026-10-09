/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_547
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=38ee14f4f33f8836fc0e209ca59c6ae8c6edf380
 */

static int vnc_update_client_sync(VncState *vs, int has_dirty)

{

    int ret = vnc_update_client(vs, has_dirty);

    vnc_jobs_join(vs);

    return ret;

}
