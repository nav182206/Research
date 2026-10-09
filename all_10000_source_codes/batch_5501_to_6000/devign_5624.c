/* 
 * Benchmark Sample ID : devign_5624
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f6774f905fb3cfdc319523ac640be30b14c1bc55
 */

void ff_mpeg_draw_horiz_band(MpegEncContext *s, int y, int h)

{

    ff_draw_horiz_band(s->avctx, &s->current_picture.f,

                       &s->last_picture.f, y, h, s->picture_structure,

                       s->first_field, s->low_delay);

}
