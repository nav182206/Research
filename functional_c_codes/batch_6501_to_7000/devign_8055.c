/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8055
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d00bff20b2b48796e4bd2d0b83819c159f60a25f
 */

static int qdm2_decode_frame(AVCodecContext *avctx,

            void *data, int *data_size,

            uint8_t *buf, int buf_size)

{

    QDM2Context *s = avctx->priv_data;



    if((buf == NULL) || (buf_size < s->checksum_size))

        return 0;



    *data_size = s->channels * s->frame_size * sizeof(int16_t);



    av_log(avctx, AV_LOG_DEBUG, "decode(%d): %p[%d] -> %p[%d]\n",

       buf_size, buf, s->checksum_size, data, *data_size);



    qdm2_decode(s, buf, data);



    // reading only when next superblock found

    if (s->sub_packet == 0) {

        return s->checksum_size;

    }



    return 0;

}
