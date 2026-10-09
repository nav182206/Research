/* 
 * Benchmark Sample ID : devign_2521
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f141b353e60f1081185927a1e74a9ab46cae8bef
 */

static void celt_search_for_intensity(OpusPsyContext *s, CeltFrame *f)
{
    int i, best_band = CELT_MAX_BANDS - 1;
    float dist, best_dist = FLT_MAX;
    /* TODO: fix, make some heuristic up here using the lambda value */
    float end_band = 0;
    for (i = f->end_band; i >= end_band; i--) {
        f->intensity_stereo = i;
        bands_dist(s, f, &dist);
        if (best_dist > dist) {
            best_dist = dist;
            best_band = i;
        }
    }
    f->intensity_stereo = best_band;
    s->avg_is_band = (s->avg_is_band + f->intensity_stereo)/2.0f;
}
