/* 
 * Benchmark Sample ID : devign_4150
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f19af812a32c1398d48c3550d11dbc6aafbb2bfc
 */

static int adx_decode_init(AVCodecContext * avctx)

{

	ADXContext *c = avctx->priv_data;



//	printf("adx_decode_init\n"); fflush(stdout);

	c->prev[0].s1 = 0;

	c->prev[0].s2 = 0;

	c->prev[1].s1 = 0;

	c->prev[1].s2 = 0;

	c->header_parsed = 0;

	c->in_temp = 0;

	return 0;

}
