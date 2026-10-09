/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2281
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7effbee66cf457c62f795d9b9ed3a1110b364b89
 */

int av_get_packet(AVIOContext *s, AVPacket *pkt, int size)

{

    int ret;


    size= ffio_limit(s, size);



    ret= av_new_packet(pkt, size);



    if(ret<0)

        return ret;



    pkt->pos= avio_tell(s);



    ret= avio_read(s, pkt->data, size);

    if(ret<=0)

        av_free_packet(pkt);

    else

        av_shrink_packet(pkt, ret);

    if (pkt->size < orig_size)

        pkt->flags |= AV_PKT_FLAG_CORRUPT;



    return ret;

}
