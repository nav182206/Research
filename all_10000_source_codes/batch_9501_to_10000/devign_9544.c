/* 
 * Benchmark Sample ID : devign_9544
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6e42e6c4b410dbef8b593c2d796a5dad95f89ee4
 */

void sws_rgb2rgb_init(int flags){

#if (defined(HAVE_MMX2) || defined(HAVE_3DNOW) || defined(HAVE_MMX))  && defined(CONFIG_GPL)

	if(flags & SWS_CPU_CAPS_MMX2)

		rgb2rgb_init_MMX2();

	else if(flags & SWS_CPU_CAPS_3DNOW)

		rgb2rgb_init_3DNOW();

	else if(flags & SWS_CPU_CAPS_MMX)

		rgb2rgb_init_MMX();

	else

#endif /* defined(HAVE_MMX2) || defined(HAVE_3DNOW) || defined(HAVE_MMX) */

		rgb2rgb_init_C();

}
