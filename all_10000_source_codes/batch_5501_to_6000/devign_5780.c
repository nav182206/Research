/* 
 * Benchmark Sample ID : devign_5780
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=47572323f2f908913b4d031af733047d481fb1f6
 */

int av_get_packet(AVIOContext *s, AVPacket *pkt, int size)

{

    int ret= av_new_packet(pkt, size);



    if(ret<0)

        return ret;



    pkt->pos= avio_tell(s);



    ret= avio_read(s, pkt->data, size);

    if(ret<=0)

        av_free_packet(pkt);

    else

        av_shrink_packet(pkt, ret);



    return ret;

}
