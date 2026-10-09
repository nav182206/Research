/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3002
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dfdb353cd565efbd1f64105ce7519ec809ad338d
 */

rdt_free_context (PayloadContext *rdt)

{

    int i;



    for (i = 0; i < MAX_STREAMS; i++)

        if (rdt->rmst[i]) {

            ff_rm_free_rmstream(rdt->rmst[i]);

            av_freep(&rdt->rmst[i]);

        }

    if (rdt->rmctx)

        av_close_input_stream(rdt->rmctx);

    av_freep(&rdt->mlti_data);

    av_free(rdt);

}
