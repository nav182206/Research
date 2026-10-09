/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1836
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f6774f905fb3cfdc319523ac640be30b14c1bc55
 */

static inline int pic_is_unused(MpegEncContext *s, Picture *pic)

{

    if (pic->f.buf[0] == NULL)

        return 1;

    if (pic->needs_realloc && !(pic->reference & DELAYED_PIC_REF))

        return 1;

    return 0;

}
