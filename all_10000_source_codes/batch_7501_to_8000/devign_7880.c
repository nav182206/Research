/* 
 * Benchmark Sample ID : devign_7880
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7d5e199ade76c53ec316ab6779800581bb47c50a
 */

static void qmp_output_type_uint64(Visitor *v, const char *name, uint64_t *obj,

                                   Error **errp)

{

    /* FIXME values larger than INT64_MAX become negative */

    QmpOutputVisitor *qov = to_qov(v);

    qmp_output_add(qov, name, qint_from_int(*obj));

}
