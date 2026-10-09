/* 
 * Benchmark Sample ID : devign_4752
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=90e56fb46d0a7add88ed463efa4e723a6238f692
 */

void migrate_decompress_threads_join(void)

{

    int i, thread_count;



    quit_decomp_thread = true;

    thread_count = migrate_decompress_threads();

    for (i = 0; i < thread_count; i++) {

        qemu_mutex_lock(&decomp_param[i].mutex);

        qemu_cond_signal(&decomp_param[i].cond);

        qemu_mutex_unlock(&decomp_param[i].mutex);

    }

    for (i = 0; i < thread_count; i++) {

        qemu_thread_join(decompress_threads + i);

        qemu_mutex_destroy(&decomp_param[i].mutex);

        qemu_cond_destroy(&decomp_param[i].cond);

        g_free(decomp_param[i].compbuf);

    }

    g_free(decompress_threads);

    g_free(decomp_param);

    decompress_threads = NULL;

    decomp_param = NULL;

}
