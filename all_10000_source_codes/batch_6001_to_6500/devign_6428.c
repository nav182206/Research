/* 
 * Benchmark Sample ID : devign_6428
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=294bb6cbd7bdc52233ddfa8f88f99aaf0d64d183
 */

static HEVCFrame *find_ref_idx(HEVCContext *s, int poc)

{

    int i;

    int LtMask = (1 << s->sps->log2_max_poc_lsb) - 1;



    for (i = 0; i < FF_ARRAY_ELEMS(s->DPB); i++) {

        HEVCFrame *ref = &s->DPB[i];

        if (ref->frame->buf[0] && (ref->sequence == s->seq_decode)) {

            if ((ref->poc & LtMask) == poc)

                return ref;

        }

    }



    for (i = 0; i < FF_ARRAY_ELEMS(s->DPB); i++) {

        HEVCFrame *ref = &s->DPB[i];

        if (ref->frame->buf[0] && ref->sequence == s->seq_decode) {

            if (ref->poc == poc || (ref->poc & LtMask) == poc)

                return ref;

        }

    }



    av_log(s->avctx, AV_LOG_ERROR,

           "Could not find ref with POC %d\n", poc);

    return NULL;

}
