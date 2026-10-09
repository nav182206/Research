/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2698
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=778358d0a8f74a76488daea3c1b6fb327d8135b4
 */

DescRing *desc_ring_alloc(Rocker *r, int index)

{

    DescRing *ring;



    ring = g_malloc0(sizeof(DescRing));

    if (!ring) {

        return NULL;

    }



    ring->r = r;

    ring->index = index;



    return ring;

}
