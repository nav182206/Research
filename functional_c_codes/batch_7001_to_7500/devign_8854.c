/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8854
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2758cdedfb7ac61f8b5e4861f99218b6fd43491d
 */

URLProtocol *ffurl_protocol_next(const URLProtocol *prev)

{

    return prev ? prev->next : first_protocol;

}
