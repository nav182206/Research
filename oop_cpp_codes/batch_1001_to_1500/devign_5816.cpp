/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5816
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

void qemu_unregister_reset(QEMUResetHandler *func, void *opaque)

{

    QEMUResetEntry *re;



    TAILQ_FOREACH(re, &reset_handlers, entry) {

        if (re->func == func && re->opaque == opaque) {

            TAILQ_REMOVE(&reset_handlers, re, entry);

            qemu_free(re);

            return;

        }

    }

}
