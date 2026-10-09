/* 
 * Benchmark Sample ID : devign_765
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a39c5c4c6baafcef0c6ec7c6f59bc3fee81b2599
 */

void ff_dv_offset_reset(DVDemuxContext *c, int64_t frame_offset)

{

    c->frames= frame_offset;

    if (c->ach)

        c->abytes= av_rescale_q(c->frames, c->sys->time_base,

                                (AVRational){8, c->ast[0]->codec->bit_rate});

    c->audio_pkt[0].size = c->audio_pkt[1].size = 0;

    c->audio_pkt[2].size = c->audio_pkt[3].size = 0;

}
