/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2726
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=61007b316cd71ee7333ff7a0a749a8949527575f
 */

static void mark_request_serialising(BdrvTrackedRequest *req, uint64_t align)

{

    int64_t overlap_offset = req->offset & ~(align - 1);

    unsigned int overlap_bytes = ROUND_UP(req->offset + req->bytes, align)

                               - overlap_offset;



    if (!req->serialising) {

        req->bs->serialising_in_flight++;

        req->serialising = true;

    }



    req->overlap_offset = MIN(req->overlap_offset, overlap_offset);

    req->overlap_bytes = MAX(req->overlap_bytes, overlap_bytes);

}
