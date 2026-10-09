/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1578
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static gboolean nbd_negotiate_continue(QIOChannel *ioc,

                                       GIOCondition condition,

                                       void *opaque)

{

    qemu_coroutine_enter(opaque, NULL);

    return TRUE;

}
