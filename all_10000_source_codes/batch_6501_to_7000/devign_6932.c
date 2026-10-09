/* 
 * Benchmark Sample ID : devign_6932
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=762bf6f4afa906a69366cbd125ef40fb788280de
 */

void av_bsf_list_free(AVBSFList **lst)

{

    int i;



    if (*lst)

        return;



    for (i = 0; i < (*lst)->nb_bsfs; ++i)

        av_bsf_free(&(*lst)->bsfs[i]);

    av_free((*lst)->bsfs);

    av_freep(lst);

}
