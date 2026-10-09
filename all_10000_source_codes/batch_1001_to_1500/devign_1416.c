/* 
 * Benchmark Sample ID : devign_1416
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=01ecb7172b684f1c4b3e748f95c5a9a494ca36ec
 */

static void quantize_and_encode_band_mips(struct AACEncContext *s, PutBitContext *pb,

                                          const float *in, float *out, int size, int scale_idx,

                                          int cb, const float lambda, int rtz)

{

    quantize_and_encode_band_cost(s, pb, in, out, NULL, size, scale_idx, cb, lambda,

                                  INFINITY, NULL, (rtz) ? ROUND_TO_ZERO : ROUND_STANDARD);

}
