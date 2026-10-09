/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5700
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=245f7b51c0ea04fb2224b1127430a096c91aee70
 */

static boolean jpeg_empty_output_buffer(j_compress_ptr cinfo)

{

    VncState *vs = cinfo->client_data;

    Buffer *buffer = &vs->tight_jpeg;



    buffer->offset = buffer->capacity;

    buffer_reserve(buffer, 2048);

    jpeg_init_destination(cinfo);

    return TRUE;

}
