/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9796
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=cb45de6798956975c4b13a6233f7a00d2239b61a
 */

opts_type_size(Visitor *v, uint64_t *obj, const char *name, Error **errp)

{

    OptsVisitor *ov = DO_UPCAST(OptsVisitor, visitor, v);

    const QemuOpt *opt;

    int64_t val;

    char *endptr;



    opt = lookup_scalar(ov, name, errp);

    if (!opt) {

        return;

    }



    val = strtosz_suffix(opt->str ? opt->str : "", &endptr,

                         STRTOSZ_DEFSUFFIX_B);

    if (val != -1 && *endptr == '\0') {

        *obj = val;

        processed(ov, name);

        return;

    }

    error_set(errp, QERR_INVALID_PARAMETER_VALUE, opt->name,

              "a size value representible as a non-negative int64");

}
