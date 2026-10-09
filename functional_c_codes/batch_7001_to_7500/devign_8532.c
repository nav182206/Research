/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8532
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6a744d261930f8101132bc6d207b6eac41d9cf18
 */

static void update_md5_sum(FlacEncodeContext *s, const int16_t *samples)

{

#if HAVE_BIGENDIAN

    int i;

    for (i = 0; i < s->frame.blocksize * s->channels; i++) {

        int16_t smp = av_le2ne16(samples[i]);

        av_md5_update(s->md5ctx, (uint8_t *)&smp, 2);

    }

#else

    av_md5_update(s->md5ctx, (const uint8_t *)samples, s->frame.blocksize*s->channels*2);

#endif

}
