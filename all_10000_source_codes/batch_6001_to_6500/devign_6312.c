/* 
 * Benchmark Sample ID : devign_6312
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=94350ab986dfce1c93fa720baf28b548c60a9879
 */

double av_expr_eval(AVExpr *e, const double *const_values, void *opaque)

{

    Parser p;



    p.const_values = const_values;

    p.opaque     = opaque;

    return eval_expr(&p, e);

}
