/* 
 * Benchmark Sample ID : devign_8960
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=92a26261d1ccc02c4fbdae2031e279009804c159
 */

static int rsd_read_packet(AVFormatContext *s, AVPacket *pkt)

{

    AVCodecContext *codec = s->streams[0]->codec;

    int ret, size = 1024;



    if (avio_feof(s->pb))

        return AVERROR_EOF;



    if (codec->codec_id == AV_CODEC_ID_ADPCM_IMA_RAD ||

        codec->codec_id == AV_CODEC_ID_ADPCM_IMA_WAV) {

        ret = av_get_packet(s->pb, pkt, codec->block_align);

    } else if (codec->codec_tag == MKTAG('W','A','D','P') &&

               codec->channels > 1) {

        int i, ch;



        av_new_packet(pkt, codec->block_align);

        for (i = 0; i < 4; i++) {

            for (ch = 0; ch < codec->channels; ch++) {

                pkt->data[ch * 8 + i * 2 + 0] = avio_r8(s->pb);

                pkt->data[ch * 8 + i * 2 + 1] = avio_r8(s->pb);

            }

        }

        ret = 0;

    } else {

        ret = av_get_packet(s->pb, pkt, size);

    }



    pkt->stream_index = 0;



    return ret;

}
