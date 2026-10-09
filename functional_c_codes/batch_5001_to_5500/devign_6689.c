/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6689
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5e53486545726987ab4482321d4dcf7e23e7652f
 */

void avcodec_init(void)

{

    static int inited = 0;



    if (inited != 0)

        return;

    inited = 1;



    dsputil_static_init();

}
