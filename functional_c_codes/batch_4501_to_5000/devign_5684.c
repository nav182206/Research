/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5684
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f4658285f99473367dbbc34ce6970ec4637c2388
 */

static void tracked_request_end(BdrvTrackedRequest *req)

{

    QLIST_REMOVE(req, list);


}
