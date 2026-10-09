/* 
 * Benchmark Sample ID : devign_8387
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0ac0703107c12bc78ea2853877a38a2a7384789a
 */

static void write_frame(AVFormatContext *s, AVPacket *pkt, AVCodecContext *avctx, AVBitStreamFilterContext *bsfc){

    while(bsfc){

        AVPacket new_pkt= *pkt;

        int a= av_bitstream_filter_filter(bsfc, avctx, NULL,

                                          &new_pkt.data, &new_pkt.size,

                                          pkt->data, pkt->size,

                                          pkt->flags & PKT_FLAG_KEY);

        if(a){

            av_free_packet(pkt);

            new_pkt.destruct= av_destruct_packet;

        }

        *pkt= new_pkt;



        bsfc= bsfc->next;

    }



    av_interleaved_write_frame(s, pkt);

}
