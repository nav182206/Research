/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4251
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ddd0e23d587e3e7ae81ee8a16a079221b0232782
 */

static int remove_decoded_packets(AVFormatContext *ctx, int64_t scr){

//    MpegMuxContext *s = ctx->priv_data;

    int i;



    for(i=0; i<ctx->nb_streams; i++){

        AVStream *st = ctx->streams[i];

        StreamInfo *stream = st->priv_data;

        PacketDesc *pkt_desc;



        while((pkt_desc= stream->predecode_packet)

              && scr > pkt_desc->dts){ //FIXME > vs >=

            if(stream->buffer_index < pkt_desc->size ||

               stream->predecode_packet == stream->premux_packet){

                av_log(ctx, AV_LOG_ERROR,

                       "buffer underflow i=%d bufi=%d size=%d\n",

                       i, stream->buffer_index, pkt_desc->size);

                break;

            }

            stream->buffer_index -= pkt_desc->size;



            stream->predecode_packet= pkt_desc->next;

            av_freep(&pkt_desc);

        }

    }



    return 0;

}
