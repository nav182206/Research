/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5538
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c49a3ec30aaa8042335656982054f02847c03aae
 */

rdt_free_extradata (PayloadContext *rdt)

{

    ff_rm_free_rmstream(rdt->rmst[0]);


    if (rdt->rmctx)

        av_close_input_stream(rdt->rmctx);

    av_freep(&rdt->mlti_data);

    av_free(rdt);

}
