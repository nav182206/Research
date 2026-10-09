/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5202
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bdf3d3bf9dce398acce608de77da205e08bdace3
 */

static void opt_top_field_first(const char *arg)

{

    top_field_first= atoi(arg);

}
