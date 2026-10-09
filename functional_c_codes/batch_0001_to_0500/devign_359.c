/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_359
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6a4d1c9063174234ca439244cf8f5f534afa1c28
 */

static const HWAccel *get_hwaccel(enum AVPixelFormat pix_fmt)

{

    int i;

    for (i = 0; hwaccels[i].name; i++)

        if (hwaccels[i].pix_fmt == pix_fmt)

            return &hwaccels[i];

    return NULL;

}
