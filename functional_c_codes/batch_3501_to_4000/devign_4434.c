/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4434
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f92f4935acd7d974adfd1deebdf1bb06cbe107ca
 */

static void up_heap(uint32_t val, uint32_t *heap, uint32_t *weights)

{

    uint32_t initial_val = heap[val];



    while (weights[initial_val] < weights[heap[val >> 1]]) {

        heap[val] = heap[val >> 1];

        val     >>= 1;

    }



    heap[val] = initial_val;

}
