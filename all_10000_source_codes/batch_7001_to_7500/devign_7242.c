/* 
 * Benchmark Sample ID : devign_7242
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4295e15aa730a95003a3639d6dad2eb1e65a59e2
 */

void qxl_guest_bug(PCIQXLDevice *qxl, const char *msg, ...)

{

#if SPICE_INTERFACE_QXL_MINOR >= 1

    qxl_send_events(qxl, QXL_INTERRUPT_ERROR);

#endif

    if (qxl->guestdebug) {

        va_list ap;

        va_start(ap, msg);

        fprintf(stderr, "qxl-%d: guest bug: ", qxl->id);

        vfprintf(stderr, msg, ap);

        fprintf(stderr, "\n");

        va_end(ap);

    }

}
