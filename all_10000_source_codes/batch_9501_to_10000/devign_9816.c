/* 
 * Benchmark Sample ID : devign_9816
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=963f76144897d3f7684d82ec21e51dd50ea1106e
 */

static av_always_inline int even(uint64_t layout)

{

    return (!layout || (layout & (layout - 1)));

}
