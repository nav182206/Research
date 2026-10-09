/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7329
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e53c9065ca08a9153ecc73a6a8940bcc6d667e58
 */

static int test_vector_dmac_scalar(AVFloatDSPContext *fdsp, AVFloatDSPContext *cdsp,

                                   const double *v1, const double *src0, double scale)

{

    LOCAL_ALIGNED(32, double, cdst, [LEN]);

    LOCAL_ALIGNED(32, double, odst, [LEN]);

    int ret;



    memcpy(cdst, v1, LEN * sizeof(*v1));

    memcpy(odst, v1, LEN * sizeof(*v1));



    cdsp->vector_dmac_scalar(cdst, src0, scale, LEN);

    fdsp->vector_dmac_scalar(odst, src0, scale, LEN);



    if (ret = compare_doubles(cdst, odst, LEN, ARBITRARY_DMAC_SCALAR_CONST))

        av_log(NULL, AV_LOG_ERROR, "vector_dmac_scalar failed\n");



    return ret;

}
