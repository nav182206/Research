/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_324
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=28f082469650a0f4c0e37b4ccd6f9514b1a0698d
 */

void qemu_co_queue_restart_all(CoQueue *queue)

{

    while (qemu_co_queue_next(queue)) {

        /* Do nothing */

    }

}
