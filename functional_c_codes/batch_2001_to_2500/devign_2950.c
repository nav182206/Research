/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2950
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=06065c451f10c7ef62cfb575a87f323a70ae1c9e
 */

void fork_start(void)

{


    mmap_fork_start();

    qemu_mutex_lock(&tb_ctx.tb_lock);

    cpu_list_lock();

}
