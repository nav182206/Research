/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2432
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c4ba5198ea48f8f648d85a853ea46e29001c12c8
 */

void av_destruct_packet(AVPacket *pkt)

{

    int i;



    av_free(pkt->data);

    pkt->data = NULL; pkt->size = 0;



    for (i = 0; i < pkt->side_data_elems; i++)

        av_free(pkt->side_data[i].data);

    av_freep(&pkt->side_data);

    pkt->side_data_elems = 0;

}
