/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_119
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=01dbbd0a9af53237cf7aac210370892208bfb957
 */

void MPV_common_end(MpegEncContext *s)

{

    int i;



    if (s->motion_val)

        free(s->motion_val);

    if (s->h263_pred) {

        free(s->dc_val[0]);

        free(s->ac_val[0]);

        free(s->coded_block);

        free(s->mbintra_table);

    }

    if (s->mbskip_table)

        free(s->mbskip_table);

    for(i=0;i<3;i++) {

        free(s->last_picture_base[i]);

        free(s->next_picture_base[i]);

        if (s->has_b_frames)

            free(s->aux_picture_base[i]);

    }

    s->context_initialized = 0;

}
