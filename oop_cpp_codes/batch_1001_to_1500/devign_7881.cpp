/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7881
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=384acbf46b70edf0d2c1648aa1a92a90bcf7057d
 */

static void bh_run_aio_completions(void *opaque)

{

    QEMUBH **bh = opaque;

    qemu_bh_delete(*bh);

    qemu_free(bh);

    qemu_aio_process_queue();

}
