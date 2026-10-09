/* 
 * Benchmark Sample ID : devign_4645
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e53c9065ca08a9153ecc73a6a8940bcc6d667e58
 */

static int test_vector_fmul_scalar(AVFloatDSPContext *fdsp, AVFloatDSPContext *cdsp,

                                   const float *v1, float scale)

{

    LOCAL_ALIGNED(32, float, cdst, [LEN]);

    LOCAL_ALIGNED(32, float, odst, [LEN]);

    int ret;



    cdsp->vector_fmul_scalar(cdst, v1, scale, LEN);

    fdsp->vector_fmul_scalar(odst, v1, scale, LEN);



    if (ret = compare_floats(cdst, odst, LEN, FLT_EPSILON))

        av_log(NULL, AV_LOG_ERROR, "vector_fmul_scalar failed\n");



    return ret;

}
