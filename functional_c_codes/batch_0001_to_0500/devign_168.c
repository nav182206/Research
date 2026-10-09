/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_168
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ad7f375df681503baa6ebef065818868e1216976
 */

static void qmp_deserialize(void **native_out, void *datap,

                            VisitorFunc visit, Error **errp)

{

    QmpSerializeData *d = datap;

    QString *output_json = qobject_to_json(qmp_output_get_qobject(d->qov));

    QObject *obj = qobject_from_json(qstring_get_str(output_json));



    QDECREF(output_json);

    d->qiv = qmp_input_visitor_new(obj);

    qobject_decref(obj);

    visit(qmp_input_get_visitor(d->qiv), native_out, errp);

}
