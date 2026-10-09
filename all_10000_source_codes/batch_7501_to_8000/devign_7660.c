/* 
 * Benchmark Sample ID : devign_7660
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ac4b32df71bd932838043a4838b86d11e169707f
 */

static void vp8_h_loop_filter_simple_c(uint8_t *dst, ptrdiff_t stride, int flim)

{

    int i;



    for (i = 0; i < 16; i++)

        if (simple_limit(dst + i * stride, 1, flim))

            filter_common(dst + i * stride, 1, 1);

}
