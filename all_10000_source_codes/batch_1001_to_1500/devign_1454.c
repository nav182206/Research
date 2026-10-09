/* 
 * Benchmark Sample ID : devign_1454
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=996922de45299878cdc4c15b72b19edf2bc618a4
 */

static void curl_close(BlockDriverState *bs)

{

    BDRVCURLState *s = bs->opaque;



    DPRINTF("CURL: Close\n");

    curl_detach_aio_context(bs);

    qemu_mutex_destroy(&s->mutex);



    g_free(s->cookie);

    g_free(s->url);




}
