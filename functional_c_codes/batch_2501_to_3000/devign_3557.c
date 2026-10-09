/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3557
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f19af812a32c1398d48c3550d11dbc6aafbb2bfc
 */

static void write_long(unsigned char *p,uint32_t v)

{

	p[0] = v>>24;

	p[1] = v>>16;

	p[2] = v>>8;

	p[3] = v;

}
