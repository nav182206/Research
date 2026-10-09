/* 
 * Benchmark Sample ID : devign_7738
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1a6d39fd71ddf90c5b76026cac4d5ff51fbaf8d8
 */

static int is_not_zero(const uint8_t *sector, int len)

{

    /*

     * Use long as the biggest available internal data type that fits into the

     * CPU register and unroll the loop to smooth out the effect of memory

     * latency.

     */



    int i;

    long d0, d1, d2, d3;

    const long * const data = (const long *) sector;



    len /= sizeof(long);



    for(i = 0; i < len; i += 4) {

        d0 = data[i + 0];

        d1 = data[i + 1];

        d2 = data[i + 2];

        d3 = data[i + 3];



        if (d0 || d1 || d2 || d3) {

            return 1;

        }

    }



    return 0;

}
