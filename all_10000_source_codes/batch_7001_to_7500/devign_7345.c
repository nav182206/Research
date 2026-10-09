/* 
 * Benchmark Sample ID : devign_7345
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=423047ea3167db5dc7d7b69165e1930710adb878
 */

static int glyph_enu_free(void *opaque, void *elem)
{
    av_free(elem);
    return 0;
}
