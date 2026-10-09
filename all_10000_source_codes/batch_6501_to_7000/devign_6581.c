/* 
 * Benchmark Sample ID : devign_6581
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a0b468f5db92daf1854c49d920169ed39e9cfb1b
 */

int av_new_packet(AVPacket *pkt, int size)

{

    uint8_t *data;

    if((unsigned)size > (unsigned)size + FF_INPUT_BUFFER_PADDING_SIZE)

        return AVERROR(ENOMEM);

    data = av_malloc(size + FF_INPUT_BUFFER_PADDING_SIZE);

    if (!data)

        return AVERROR(ENOMEM);

    memset(data + size, 0, FF_INPUT_BUFFER_PADDING_SIZE);



    av_init_packet(pkt);

    pkt->data = data;

    pkt->size = size;

    pkt->destruct = av_destruct_packet;

    return 0;

}
