/* 
 * Benchmark Sample ID : devign_8958
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b0cd14fb1dab4b044f7fe6b53ac635409849de77
 */

static const HWAccel *get_hwaccel(enum AVPixelFormat pix_fmt, enum HWAccelID selected_hwaccel_id)

{

    int i;

    for (i = 0; hwaccels[i].name; i++)

        if (hwaccels[i].pix_fmt == pix_fmt &&

            (!selected_hwaccel_id || selected_hwaccel_id == HWACCEL_AUTO || hwaccels[i].id == selected_hwaccel_id))

            return &hwaccels[i];

    return NULL;

}
