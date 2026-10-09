/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7811
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0c46e958d1fd3817b8e9fa048d0450d509c80378
 */

static int mxf_get_d10_aes3_packet(AVIOContext *pb, AVStream *st, AVPacket *pkt, int64_t length)

{

    const uint8_t *buf_ptr, *end_ptr;

    uint8_t *data_ptr;

    int i;



    if (length > 61444) /* worst case PAL 1920 samples 8 channels */

        return -1;

    av_new_packet(pkt, length);

    avio_read(pb, pkt->data, length);

    data_ptr = pkt->data;

    end_ptr = pkt->data + length;

    buf_ptr = pkt->data + 4; /* skip SMPTE 331M header */

    for (; buf_ptr < end_ptr; ) {

        for (i = 0; i < st->codec->channels; i++) {

            uint32_t sample = bytestream_get_le32(&buf_ptr);

            if (st->codec->bits_per_coded_sample == 24)

                bytestream_put_le24(&data_ptr, (sample >> 4) & 0xffffff);

            else

                bytestream_put_le16(&data_ptr, (sample >> 12) & 0xffff);

        }

        buf_ptr += 32 - st->codec->channels*4; // always 8 channels stored SMPTE 331M

    }

    pkt->size = data_ptr - pkt->data;

    return 0;

}
