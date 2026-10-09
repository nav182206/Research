/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3828
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ef1e1e0782e99c9dcf2b35e5310cdd8ca9211374
 */

void desc_ring_free(DescRing *ring)

{

    if (ring->info) {

        g_free(ring->info);

    }

    g_free(ring);

}
