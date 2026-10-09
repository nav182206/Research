/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6107
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=06bf6d3bc04979bd39ecdc7311d0daf8aee7e10f
 */

static void null_draw_slice(AVFilterLink *inlink, int y, int h, int slice_dir) { }
