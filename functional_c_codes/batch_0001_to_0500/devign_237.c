/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_237
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f17fd4fdf0df3d2f3444399d04c38d22b9a3e1b7
 */

opts_type_size(Visitor *v, const char *name, uint64_t *obj, Error **errp)

{

    OptsVisitor *ov = to_ov(v);

    const QemuOpt *opt;

    int64_t val;



    opt = lookup_scalar(ov, name, errp);

    if (!opt) {

        return;

    }



    val = qemu_strtosz(opt->str ? opt->str : "", NULL);

    if (val < 0) {

        error_setg(errp, QERR_INVALID_PARAMETER_VALUE, opt->name,

                   "a size value representible as a non-negative int64");

        return;

    }



    *obj = val;

    processed(ov, name);

}
