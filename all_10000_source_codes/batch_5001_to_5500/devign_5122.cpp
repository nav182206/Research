/* 
 * Benchmark Sample ID : devign_5122
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ec4c48397641dbaf4ae8df36c32aaa5a311a11bf
 */

static const AVClass *ff_avio_child_class_next(const AVClass *prev)

{

    return prev ? NULL : &ffurl_context_class;

}
