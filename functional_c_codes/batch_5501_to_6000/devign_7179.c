/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7179
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6919e54c00b750cd3d9d756258d3677df52f96a9
 */

int av_interleave_packet_per_dts(AVFormatContext *s, AVPacket *out, AVPacket *pkt, int flush){

    AVPacketList *pktl, **next_point, *this_pktl;

    int stream_count=0;

    int streams[MAX_STREAMS];



    if(pkt){

        AVStream *st= s->streams[ pkt->stream_index];



//        assert(pkt->destruct != av_destruct_packet); //FIXME



        this_pktl = av_mallocz(sizeof(AVPacketList));

        this_pktl->pkt= *pkt;

        if(pkt->destruct == av_destruct_packet)

            pkt->destruct= NULL; // not shared -> must keep original from being freed

        else

            av_dup_packet(&this_pktl->pkt);  //shared -> must dup



        next_point = &s->packet_buffer;

        while(*next_point){

            AVStream *st2= s->streams[ (*next_point)->pkt.stream_index];

            int64_t left=  st2->time_base.num * (int64_t)st ->time_base.den;

            int64_t right= st ->time_base.num * (int64_t)st2->time_base.den;

            if((*next_point)->pkt.dts * left > pkt->dts * right) //FIXME this can overflow

                break;

            next_point= &(*next_point)->next;

        }

        this_pktl->next= *next_point;

        *next_point= this_pktl;

    }



    memset(streams, 0, sizeof(streams));

    pktl= s->packet_buffer;

    while(pktl){

//av_log(s, AV_LOG_DEBUG, "show st:%d dts:%"PRId64"\n", pktl->pkt.stream_index, pktl->pkt.dts);

        if(streams[ pktl->pkt.stream_index ] == 0)

            stream_count++;

        streams[ pktl->pkt.stream_index ]++;

        pktl= pktl->next;

    }



    if(s->nb_streams == stream_count || (flush && stream_count)){

        pktl= s->packet_buffer;

        *out= pktl->pkt;



        s->packet_buffer= pktl->next;

        av_freep(&pktl);

        return 1;

    }else{

        av_init_packet(out);

        return 0;

    }

}
