/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2413
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=324ff59444ff5470bb325ff1e2be7c4b054fc944
 */

void ff_interleave_add_packet(AVFormatContext *s, AVPacket *pkt,

                              int (*compare)(AVFormatContext *, AVPacket *, AVPacket *))

{

    AVPacketList **next_point, *this_pktl;



    this_pktl      = av_mallocz(sizeof(AVPacketList));

    this_pktl->pkt = *pkt;

#if FF_API_DESTRUCT_PACKET

FF_DISABLE_DEPRECATION_WARNINGS

    pkt->destruct  = NULL;           // do not free original but only the copy

FF_ENABLE_DEPRECATION_WARNINGS

#endif

    pkt->buf       = NULL;

    av_dup_packet(&this_pktl->pkt);  // duplicate the packet if it uses non-alloced memory



    if (s->streams[pkt->stream_index]->last_in_packet_buffer) {

        next_point = &(s->streams[pkt->stream_index]->last_in_packet_buffer->next);

    } else

        next_point = &s->packet_buffer;



    if (*next_point) {

        if (compare(s, &s->packet_buffer_end->pkt, pkt)) {

            while (!compare(s, &(*next_point)->pkt, pkt))

                next_point = &(*next_point)->next;

            goto next_non_null;

        } else {

            next_point = &(s->packet_buffer_end->next);

        }

    }

    assert(!*next_point);



    s->packet_buffer_end = this_pktl;

next_non_null:



    this_pktl->next = *next_point;



    s->streams[pkt->stream_index]->last_in_packet_buffer =

        *next_point                                      = this_pktl;

}
