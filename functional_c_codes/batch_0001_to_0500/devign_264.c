/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_264
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7d5e199ade76c53ec316ab6779800581bb47c50a
 */

static void qmp_serialize(void *native_in, void **datap,

                          VisitorFunc visit, Error **errp)

{

    QmpSerializeData *d = g_malloc0(sizeof(*d));



    d->qov = qmp_output_visitor_new(&d->obj);

    visit(d->qov, &native_in, errp);

    *datap = d;

}
