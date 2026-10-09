/* 
 * Benchmark Sample ID : devign_1928
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=428098165de4c3edfe42c1b7f00627d287015863
 */

SwsFunc yuv2rgb_init_mlib(SwsContext *c)

{

	switch(c->dstFormat){

	case PIX_FMT_RGB24: return mlib_YUV2RGB420_24;

	case PIX_FMT_BGR32: return mlib_YUV2ARGB420_32;

	case PIX_FMT_RGB32: return mlib_YUV2ABGR420_32;

	default: return NULL;

	}

}
