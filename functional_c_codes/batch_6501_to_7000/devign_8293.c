/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8293
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=acf6e5f0962c4be670d4a93ede77423512521876
 */

static bool check_overlapping_aiocb(BDRVSheepdogState *s, SheepdogAIOCB *aiocb)

{

    SheepdogAIOCB *cb;



    QLIST_FOREACH(cb, &s->inflight_aiocb_head, aiocb_siblings) {

        if (AIOCBOverlapping(aiocb, cb)) {

            return true;

        }

    }



    QLIST_INSERT_HEAD(&s->inflight_aiocb_head, aiocb, aiocb_siblings);

    return false;

}
