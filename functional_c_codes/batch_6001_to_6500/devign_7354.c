/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7354
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3715d841a619f1cbc4776d9b00575dae6fb6534a
 */

WINDOW_FUNC(eight_short)

{

    const float *swindow = sce->ics.use_kb_window[0] ? ff_aac_kbd_short_128 : ff_sine_128;

    const float *pwindow = sce->ics.use_kb_window[1] ? ff_aac_kbd_short_128 : ff_sine_128;

    const float *in = audio + 448;

    float *out = sce->ret;



    for (int w = 0; w < 8; w++) {

        dsp->vector_fmul        (out, in, w ? pwindow : swindow, 128);

        out += 128;

        in  += 128;

        dsp->vector_fmul_reverse(out, in, swindow, 128);

        out += 128;

    }

}
