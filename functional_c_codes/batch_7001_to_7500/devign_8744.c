/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8744
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=202a6697ba54293235ce2d7bd5724f4f461e417f
 */

rdt_new_extradata (void)

{

    PayloadContext *rdt = av_mallocz(sizeof(PayloadContext));



    av_open_input_stream(&rdt->rmctx, NULL, "", &rdt_demuxer, NULL);



    return rdt;

}
