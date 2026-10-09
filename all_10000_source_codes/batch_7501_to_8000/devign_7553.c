/* 
 * Benchmark Sample ID : devign_7553
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=710aec915d208246891b68e2ba61b54951edc508
 */

static QDict *build_qmp_error_dict(const QError *err)

{

    QObject *obj;



    obj = qobject_from_jsonf("{ 'error': { 'class': %s, 'desc': %p } }",

                             ErrorClass_lookup[err->err_class],

                             qerror_human(err));



    return qobject_to_qdict(obj);

}
