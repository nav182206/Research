/* 
 * Benchmark Sample ID : devign_2453
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bae8196d9f97916de6323e70e3e374362ee16ec4
 */

static void coroutine_fn mirror_pause(BlockJob *job)

{

    MirrorBlockJob *s = container_of(job, MirrorBlockJob, common);



    mirror_drain(s);

}
