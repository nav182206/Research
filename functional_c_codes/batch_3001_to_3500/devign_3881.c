/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3881
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2ed0f76655a76cc49f8a1a1d59e545f5906e7924
 */

av_cold void ff_h264_free_context(H264Context *h)

{

    int i;



    free_tables(h); //FIXME cleanup init stuff perhaps



    for(i = 0; i < MAX_SPS_COUNT; i++)

        av_freep(h->sps_buffers + i);



    for(i = 0; i < MAX_PPS_COUNT; i++)

        av_freep(h->pps_buffers + i);

}
