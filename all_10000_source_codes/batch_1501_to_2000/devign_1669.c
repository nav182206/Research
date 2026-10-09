/* 
 * Benchmark Sample ID : devign_1669
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=67fa02ed794f9505bd9c3584c14bfb61c895f5bc
 */

static inline uint32_t celt_icwrsi(uint32_t N, const int *y)

{

    int i, idx = 0, sum = 0;

    for (i = N - 1; i >= 0; i--) {

        const uint32_t i_s = CELT_PVQ_U(N - i, sum + FFABS(y[i]) + 1);

        idx += CELT_PVQ_U(N - i, sum) + (y[i] < 0)*i_s;

        sum += FFABS(y[i]);

    }

    return idx;

}
