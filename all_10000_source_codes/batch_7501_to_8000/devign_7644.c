/* 
 * Benchmark Sample ID : devign_7644
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f19442c069929727b19c948619488370d279e177
 */

static inline uint32_t celt_icwrsi(uint32_t N, uint32_t K, const int *y)

{

    int i, idx = 0, sum = 0;

    for (i = N - 1; i >= 0; i--) {

        const uint32_t i_s = CELT_PVQ_U(N - i, sum + FFABS(y[i]) + 1);

        idx += CELT_PVQ_U(N - i, sum) + (y[i] < 0)*i_s;

        sum += FFABS(y[i]);

    }

    av_assert0(sum == K);

    return idx;

}
