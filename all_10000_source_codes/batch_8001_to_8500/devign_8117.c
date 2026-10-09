/* 
 * Benchmark Sample ID : devign_8117
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0e4b185a8df12c7b42642699a8df45e0de48de07
 */

void rtp_parse_close(RTPDemuxContext *s)

{

    // TODO: fold this into the protocol specific data fields.



    if (!strcmp(ff_rtp_enc_name(s->payload_type), "MP2T")) {

        ff_mpegts_parse_close(s->ts);

    }

    av_free(s);

}
