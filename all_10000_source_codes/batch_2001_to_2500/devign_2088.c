/* 
 * Benchmark Sample ID : devign_2088
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9a6d1acb3e752e1e0b693cc0491fa12875b76be0
 */

Object *user_creatable_add_opts(QemuOpts *opts, Error **errp)

{

    Visitor *v;

    QDict *pdict;

    Object *obj;

    const char *id = qemu_opts_id(opts);

    const char *type = qemu_opt_get(opts, "qom-type");



    if (!type) {

        error_setg(errp, QERR_MISSING_PARAMETER, "qom-type");

        return NULL;

    }

    if (!id) {

        error_setg(errp, QERR_MISSING_PARAMETER, "id");

        return NULL;

    }



    pdict = qemu_opts_to_qdict(opts, NULL);

    qdict_del(pdict, "qom-type");

    qdict_del(pdict, "id");



    v = opts_visitor_new(opts);

    obj = user_creatable_add_type(type, id, pdict, v, errp);

    visit_free(v);



    QDECREF(pdict);

    return obj;

}
