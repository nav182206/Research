/* 
 * Benchmark Sample ID : devign_4667
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6c3cb02a742f0ce32a85e86738a18e3d6d711d59
 */

static int find_headers_search_validate(FLACParseContext *fpc, int offset)
{
    FLACFrameInfo fi;
    uint8_t *header_buf;
    int size = 0;
    header_buf = flac_fifo_read_wrap(fpc, offset,
                                     MAX_FRAME_HEADER_SIZE,
                                     &fpc->wrap_buf,
                                     &fpc->wrap_buf_allocated_size);
    if (frame_header_is_valid(fpc->avctx, header_buf, &fi)) {
        FLACHeaderMarker **end_handle = &fpc->headers;
        int i;
        size = 0;
        while (*end_handle) {
            end_handle = &(*end_handle)->next;
            size++;
        *end_handle = av_mallocz(sizeof(**end_handle));
        if (!*end_handle) {
            av_log(fpc->avctx, AV_LOG_ERROR,
                   "couldn't allocate FLACHeaderMarker\n");
        (*end_handle)->fi           = fi;
        (*end_handle)->offset       = offset;
        (*end_handle)->link_penalty = av_malloc(sizeof(int) *
                                            FLAC_MAX_SEQUENTIAL_HEADERS);
        for (i = 0; i < FLAC_MAX_SEQUENTIAL_HEADERS; i++)
            (*end_handle)->link_penalty[i] = FLAC_HEADER_NOT_PENALIZED_YET;
        fpc->nb_headers_found++;
        size++;
    return size;
