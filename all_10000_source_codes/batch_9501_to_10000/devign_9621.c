/* 
 * Benchmark Sample ID : devign_9621
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7f2fe444a39bca733d390b6608801c5f002bfd31
 */

void MPV_frame_end(MpegEncContext *s)

{

    /* draw edge for correct motion prediction if outside */

    if (s->pict_type != B_TYPE && !s->intra_only) {

      if(s->avctx==NULL || s->avctx->codec->id!=CODEC_ID_MPEG4 || s->divx_version==500){

        draw_edges(s->current_picture[0], s->linesize, s->mb_width*16, s->mb_height*16, EDGE_WIDTH);

        draw_edges(s->current_picture[1], s->linesize/2, s->mb_width*8, s->mb_height*8, EDGE_WIDTH/2);

        draw_edges(s->current_picture[2], s->linesize/2, s->mb_width*8, s->mb_height*8, EDGE_WIDTH/2);

      }else{

        /* mpeg4? / opendivx / xvid */

        draw_edges(s->current_picture[0], s->linesize, s->width, s->height, EDGE_WIDTH);

        draw_edges(s->current_picture[1], s->linesize/2, s->width/2, s->height/2, EDGE_WIDTH/2);

        draw_edges(s->current_picture[2], s->linesize/2, s->width/2, s->height/2, EDGE_WIDTH/2);

      }

    }

    emms_c();

    

    if(s->pict_type!=B_TYPE){

        s->last_non_b_pict_type= s->pict_type;

        s->last_non_b_qscale= s->qscale;

        s->last_non_b_mc_mb_var= s->mc_mb_var;

        s->num_available_buffers++;

        if(s->num_available_buffers>2) s->num_available_buffers= 2;

    }

}
