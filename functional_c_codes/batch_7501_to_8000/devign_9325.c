/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9325
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c6a6a5e3bb7120e1eb33eca6364a290229c1e72e
 */

putsum(uint8_t *data, uint32_t n, uint32_t sloc, uint32_t css, uint32_t cse)

{

    if (cse && cse < n)

        n = cse + 1;

    if (sloc < n-1)

        cpu_to_be16wu((uint16_t *)(data + sloc),

                      do_cksum(data + css, data + n));

}
