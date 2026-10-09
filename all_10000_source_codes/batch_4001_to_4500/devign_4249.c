/* 
 * Benchmark Sample ID : devign_4249
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5c95de150f3b18f2e76fed670d6ea579feab1206
 */

static int xvid_strip_vol_header(AVCodecContext *avctx, AVPacket *pkt,

                                 unsigned int header_len,

                                 unsigned int frame_len)

{

    int vo_len = 0, i;



    for (i = 0; i < header_len - 3; i++) {

        if (pkt->data[i]     == 0x00 &&

            pkt->data[i + 1] == 0x00 &&

            pkt->data[i + 2] == 0x01 &&

            pkt->data[i + 3] == 0xB6) {

            vo_len = i;

            break;

        }

    }



    if (vo_len > 0) {

        /* We need to store the header, so extract it */

        if (!avctx->extradata) {

            avctx->extradata = av_malloc(vo_len);



            memcpy(avctx->extradata, pkt->data, vo_len);

            avctx->extradata_size = vo_len;

        }

        /* Less dangerous now, memmove properly copies the two

         * chunks of overlapping data */

        memmove(pkt->data, &pkt->data[vo_len], frame_len - vo_len);

        pkt->size = frame_len - vo_len;

    }

    return 0;

}
