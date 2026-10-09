/* 
 * Benchmark Sample ID : devign_491
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=245f7b51c0ea04fb2224b1127430a096c91aee70
 */

static void jpeg_term_destination(j_compress_ptr cinfo)

{

    VncState *vs = cinfo->client_data;

    Buffer *buffer = &vs->tight_jpeg;



    buffer->offset = buffer->capacity - cinfo->dest->free_in_buffer;

}
