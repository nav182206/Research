/* 
 * Benchmark Sample ID : devign_1333
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6ad45600313f0df1abf31abdd28f4339dbdc7ca0
 */

static int decode_pivot(MSS1Context *ctx, ArithCoder *acoder, int base)

{

    int val, inv;



    inv = arith_get_model_sym(acoder, &ctx->edge_mode);

    val = arith_get_model_sym(acoder, &ctx->pivot) + 1;



    if (val > 2) {

        if ((base + 1) / 2 - 2 <= 0) {

            ctx->corrupted = 1;

            return 0;

        }

        val = arith_get_number(acoder, (base + 1) / 2 - 2) + 3;

    }



    if (val == base) {

        ctx->corrupted = 1;

        return 0;

    }



    return inv ? base - val : val;

}
