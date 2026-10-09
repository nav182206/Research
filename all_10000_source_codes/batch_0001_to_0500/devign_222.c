/* 
 * Benchmark Sample ID : devign_222
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=dae7ff04160901a30a35af05f2f149b289c4f0b1
 */

static void decode_ac_filter(WmallDecodeCtx *s)

{

    int i;

    s->acfilter_order = get_bits(&s->gb, 4) + 1;

    s->acfilter_scaling = get_bits(&s->gb, 4);



    for(i = 0; i < s->acfilter_order; i++) {

	s->acfilter_coeffs[i] = get_bits(&s->gb, s->acfilter_scaling) + 1;

    }

}
