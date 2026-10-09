/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7017
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=aff6cebb41669a25008f76ce3c310001613e6263
 */

static int set_expr(AVExpr **pexpr, const char *expr, void *log_ctx)

{

    int ret;



    if (*pexpr)

        av_expr_free(*pexpr);

    *pexpr = NULL;

    ret = av_expr_parse(pexpr, expr, var_names,

                        NULL, NULL, NULL, NULL, 0, log_ctx);

    if (ret < 0)

        av_log(log_ctx, AV_LOG_ERROR,

               "Error when evaluating the expression '%s'\n", expr);

    return ret;

}
