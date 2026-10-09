/* 
 * Benchmark Sample ID : devign_3025
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=37f32349ea43f41ee8b9a253977ce1e46f576fc7
 */

int qemu_opts_foreach(QemuOptsList *list, qemu_opts_loopfunc func,

                      void *opaque, Error **errp)

{

    Location loc;

    QemuOpts *opts;

    int rc;



    loc_push_none(&loc);

    QTAILQ_FOREACH(opts, &list->head, next) {

        loc_restore(&opts->loc);

        rc = func(opaque, opts, errp);

        if (rc) {

            return rc;

        }

        assert(!errp || !*errp);

    }

    loc_pop(&loc);

    return 0;

}
