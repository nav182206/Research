/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9005
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e55376a1fd5abebbb0a082aa20739d58c2260a37
 */

static int append_flv_data(RTMPContext *rt, RTMPPacket *pkt, int skip)

{

    int old_flv_size, ret;

    PutByteContext pbc;

    const uint8_t *data = pkt->data + skip;

    const int size      = pkt->size - skip;

    uint32_t ts         = pkt->timestamp;



    if (pkt->type == RTMP_PT_AUDIO) {

        rt->has_audio = 1;

    } else if (pkt->type == RTMP_PT_VIDEO) {

        rt->has_video = 1;

    }



    old_flv_size = update_offset(rt, size + 15);



    if ((ret = av_reallocp(&rt->flv_data, rt->flv_size)) < 0) {

        rt->flv_size = rt->flv_off = 0;

        return ret;

    }

    bytestream2_init_writer(&pbc, rt->flv_data, rt->flv_size);

    bytestream2_skip_p(&pbc, old_flv_size);

    bytestream2_put_byte(&pbc, pkt->type);

    bytestream2_put_be24(&pbc, size);

    bytestream2_put_be24(&pbc, ts);

    bytestream2_put_byte(&pbc, ts >> 24);

    bytestream2_put_be24(&pbc, 0);

    bytestream2_put_buffer(&pbc, data, size);

    bytestream2_put_be32(&pbc, 0);



    return 0;

}
