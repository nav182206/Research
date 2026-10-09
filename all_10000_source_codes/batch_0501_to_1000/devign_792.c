/* 
 * Benchmark Sample ID : devign_792
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fd8b90f5f63de12c1ee1ec1cbe99791c5629c582
 */

av_cold void ff_vp9dsp_init(VP9DSPContext *dsp, int bpp)

{

    if (bpp == 8) {

        ff_vp9dsp_init_8(dsp);

    } else if (bpp == 10) {

        ff_vp9dsp_init_10(dsp);

    } else {

        av_assert0(bpp == 12);

        ff_vp9dsp_init_12(dsp);

    }



    if (ARCH_X86) ff_vp9dsp_init_x86(dsp, bpp);

    if (ARCH_MIPS) ff_vp9dsp_init_mips(dsp, bpp);

}
