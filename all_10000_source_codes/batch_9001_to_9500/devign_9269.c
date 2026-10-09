/* 
 * Benchmark Sample ID : devign_9269
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f929ab0569ff31ed5a59b0b0adb7ce09df3fca39
 */

static inline int pic_is_unused(MpegEncContext *s, Picture *pic)

{

    if (pic->f->buf[0] == NULL)

        return 1;

    if (pic->needs_realloc && !(pic->reference & DELAYED_PIC_REF))

        return 1;

    return 0;

}
