/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1659
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8cd8c8331730fbaac5066bfd66e15b39a85ce537
 */

static void get_lag(float *buf, const float *new, LongTermPrediction *ltp)

{

    int i, j, lag, max_corr = 0;

    float max_ratio;

    for (i = 0; i < 2048; i++) {

        float corr, s0 = 0.0f, s1 = 0.0f;

        const int start = FFMAX(0, i - 1024);

        for (j = start; j < 2048; j++) {

            const int idx = j - i + 1024;

            s0 += new[j]*buf[idx];

            s1 += buf[idx]*buf[idx];

        }

        corr = s1 > 0.0f ? s0/sqrt(s1) : 0.0f;

        if (corr > max_corr) {

            max_corr = corr;

            lag = i;

            max_ratio = corr/(2048-start);

        }

    }

    ltp->lag = FFMAX(av_clip_uintp2(lag, 11), 0);

    ltp->coef_idx = quant_array_idx(max_ratio, ltp_coef, 8);

    ltp->coef = ltp_coef[ltp->coef_idx];

}
