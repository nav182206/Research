/* 
 * Benchmark Sample ID : devign_3584
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d95704341280fc521dc2b16bbbc5858f6647e2c3
 */

opts_start_optional(Visitor *v, bool *present, const char *name,

                       Error **errp)

{

    OptsVisitor *ov = DO_UPCAST(OptsVisitor, visitor, v);



    /* we only support a single mandatory scalar field in a list node */

    assert(ov->repeated_opts == NULL);

    *present = (lookup_distinct(ov, name, NULL) != NULL);

}
