/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5943
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c4e6024adc18df8ff82157227e2b4159f77951f9
 */

static void close_slaves(AVFormatContext *avf)

{

    TeeContext *tee = avf->priv_data;

    AVFormatContext *avf2;

    unsigned i, j;



    for (i = 0; i < tee->nb_slaves; i++) {

        avf2 = tee->slaves[i].avf;



        for (j = 0; j < avf2->nb_streams; j++) {

            AVBitStreamFilterContext *bsf_next, *bsf = tee->slaves[i].bsfs[j];

            while (bsf) {

                bsf_next = bsf->next;

                av_bitstream_filter_close(bsf);

                bsf = bsf_next;

            }

        }

        av_freep(&tee->slaves[i].stream_map);




        avio_close(avf2->pb);

        avf2->pb = NULL;

        avformat_free_context(avf2);

        tee->slaves[i].avf = NULL;

    }

}
