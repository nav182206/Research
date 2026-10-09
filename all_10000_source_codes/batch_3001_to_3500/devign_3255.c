/* 
 * Benchmark Sample ID : devign_3255
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f6774f905fb3cfdc319523ac640be30b14c1bc55
 */

static void init_block_index(VC1Context *v)

{

    MpegEncContext *s = &v->s;

    ff_init_block_index(s);

    if (v->field_mode && !(v->second_field ^ v->tff)) {

        s->dest[0] += s->current_picture_ptr->f.linesize[0];

        s->dest[1] += s->current_picture_ptr->f.linesize[1];

        s->dest[2] += s->current_picture_ptr->f.linesize[2];

    }

}
