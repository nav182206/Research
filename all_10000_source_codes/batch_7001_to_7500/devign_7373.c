/* 
 * Benchmark Sample ID : devign_7373
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static void restart_coroutine(void *opaque)

{

    Coroutine *co = opaque;



    DPRINTF("co=%p", co);



    qemu_coroutine_enter(co, NULL);

}
