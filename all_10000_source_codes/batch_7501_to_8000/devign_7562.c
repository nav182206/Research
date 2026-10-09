/* 
 * Benchmark Sample ID : devign_7562
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=29fb49194bedc74ac9be0b49b6b42dcfeb6222d9
 */

void av_set_cpu_flags_mask(int mask)

{

    checked       = 0;

    flags         = av_get_cpu_flags() & mask;

    checked       = 1;

}
