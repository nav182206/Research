/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4659
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3228ac730c11eca49d5680d5550128e397061c85
 */

av_cold void ff_vc2enc_free_transforms(VC2TransformContext *s)

{

    av_freep(&s->buffer);

}
