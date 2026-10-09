/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5197
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a553c6a347d3d28d7ee44c3df3d5c4ee780dba23
 */

static inline int pic_is_unused(H264Context *h, Picture *pic)

{

    if (pic->f.data[0] == NULL)

        return 1;

    if (pic->needs_realloc && !(pic->reference & DELAYED_PIC_REF))

        return 1;

    return 0;

}
