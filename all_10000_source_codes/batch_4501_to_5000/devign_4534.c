/* 
 * Benchmark Sample ID : devign_4534
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f19af812a32c1398d48c3550d11dbc6aafbb2bfc
 */

static void adx_decode_stereo(short *out,const unsigned char *in,PREV *prev)

{

	short tmp[32*2];

	int i;



	adx_decode(tmp   ,in   ,prev);

	adx_decode(tmp+32,in+18,prev+1);

	for(i=0;i<32;i++) {

		out[i*2]   = tmp[i];

		out[i*2+1] = tmp[i+32];

	}

}
