/* 
 * Benchmark Sample ID : devign_9370
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d17008bc2914d62fd0af6a8f313604ae9f9a102c
 */

static uint32_t hpet_time_after(uint64_t a, uint64_t b)

{

    return ((int32_t)(b) - (int32_t)(a) < 0);

}
