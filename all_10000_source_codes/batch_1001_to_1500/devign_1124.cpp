/* 
 * Benchmark Sample ID : devign_1124
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=464a631c34967f4c326b2de8b3cf4903d3e5b01c
 */

static void opt_video_rc_override_string(char *arg)

{

    video_rc_override_string = arg;

}
