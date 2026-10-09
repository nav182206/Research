/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2980
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3b098d56979d2f7fd707c5be85555d114353a28d
 */

static void qmp_cleanup(void *datap)

{

    QmpSerializeData *d = datap;

    visit_free(qmp_output_get_visitor(d->qov));

    visit_free(d->qiv);



    g_free(d);

}
