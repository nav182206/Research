/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5413
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6ea428789371fa0601e9ebb5b7f2216d4e73e831
 */

static void dss_sp_shift_sq_sub(const int32_t *filter_buf,

                                int32_t *error_buf, int32_t *dst)

{

    int a;



    for (a = 0; a < 72; a++) {

        int i, tmp;



        tmp = dst[a] * filter_buf[0];



        for (i = 14; i > 0; i--)

            tmp -= error_buf[i] * (unsigned)filter_buf[i];



        for (i = 14; i > 0; i--)

            error_buf[i] = error_buf[i - 1];



        tmp = (tmp + 4096) >> 13;



        error_buf[1] = tmp;



        dst[a] = av_clip_int16(tmp);

    }

}
