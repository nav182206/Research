/* 
 * Benchmark Sample ID : devign_4614
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0424e052f83adc422d8a746e3cdc5ab6bc28679e
 */

static int decode_frame(AVCodecContext *avctx,

                             void *data, int *data_size,

                             AVPacket *avpkt)

{

    const uint8_t *buf = avpkt->data;

    int buf_size = avpkt->size;

    H264Context *h = avctx->priv_data;

    MpegEncContext *s = &h->s;

    AVFrame *pict = data;

    int buf_index;



    s->flags= avctx->flags;

    s->flags2= avctx->flags2;



   /* end of stream, output what is still in the buffers */

 out:

    if (buf_size == 0) {

        Picture *out;

        int i, out_idx;



        s->current_picture_ptr = NULL;



//FIXME factorize this with the output code below

        out = h->delayed_pic[0];

        out_idx = 0;

        for(i=1; h->delayed_pic[i] && !h->delayed_pic[i]->key_frame && !h->delayed_pic[i]->mmco_reset; i++)

            if(h->delayed_pic[i]->poc < out->poc){

                out = h->delayed_pic[i];

                out_idx = i;

            }



        for(i=out_idx; h->delayed_pic[i]; i++)

            h->delayed_pic[i] = h->delayed_pic[i+1];



        if(out){

            *data_size = sizeof(AVFrame);

            *pict= *(AVFrame*)out;

        }



        return 0;

    }



    buf_index=decode_nal_units(h, buf, buf_size);

    if(buf_index < 0)

        return -1;



    if (!s->current_picture_ptr && h->nal_unit_type == NAL_END_SEQUENCE) {

        buf_size = 0;

        goto out;

    }



    if(!(s->flags2 & CODEC_FLAG2_CHUNKS) && !s->current_picture_ptr){

        if (avctx->skip_frame >= AVDISCARD_NONREF)

            return 0;

        av_log(avctx, AV_LOG_ERROR, "no frame!\n");

        return -1;

    }



    if(!(s->flags2 & CODEC_FLAG2_CHUNKS) || (s->mb_y >= s->mb_height && s->mb_height)){



        if(s->flags2 & CODEC_FLAG2_CHUNKS) decode_postinit(h);



        field_end(h, 0);



        if (!h->next_output_pic) {

            /* Wait for second field. */

            *data_size = 0;



        } else {

            *data_size = sizeof(AVFrame);

            *pict = *(AVFrame*)h->next_output_pic;

        }

    }



    assert(pict->data[0] || !*data_size);

    ff_print_debug_info(s, pict);

//printf("out %d\n", (int)pict->data[0]);



    return get_consumed_bytes(s, buf_index, buf_size);

}
