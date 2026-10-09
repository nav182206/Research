/* 
 * Benchmark Sample ID : devign_3674
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9f14b0add1dcdbfa2ee61051d068211fb0a1fcc9
 */

static void rng_egd_free_request(RngRequest *req)

{

    g_free(req->data);

    g_free(req);

}
