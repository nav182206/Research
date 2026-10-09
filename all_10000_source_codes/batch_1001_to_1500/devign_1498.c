/* 
 * Benchmark Sample ID : devign_1498
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=da3c3c446cb434be9d0025f519e00c2385135c85
 */

static int packet_alloc(AVBufferRef **buf, int size)

{

    int ret;

    if ((unsigned)size >= (unsigned)size + AV_INPUT_BUFFER_PADDING_SIZE)

        return AVERROR(EINVAL);



    ret = av_buffer_realloc(buf, size + AV_INPUT_BUFFER_PADDING_SIZE);

    if (ret < 0)

        return ret;



    memset((*buf)->data + size, 0, AV_INPUT_BUFFER_PADDING_SIZE);



    return 0;

}
