/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4053
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4a2594ddd35de7ae7c8cd9c6828cfe72245e6dc5
 */

int qemu_opts_foreach(QemuOptsList *list, qemu_opts_loopfunc func, void *opaque,

                      int abort_on_failure)

{

    QemuOpts *opts;

    int rc = 0;



    QTAILQ_FOREACH(opts, &list->head, next) {

        rc = func(opts, opaque);

        if (abort_on_failure  &&  rc != 0)

            break;

    }

    return rc;

}
