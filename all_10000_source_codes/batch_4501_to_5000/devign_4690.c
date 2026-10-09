/* 
 * Benchmark Sample ID : devign_4690
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d95704341280fc521dc2b16bbbc5858f6647e2c3
 */

opts_next_list(Visitor *v, GenericList **list, Error **errp)

{

    OptsVisitor *ov = DO_UPCAST(OptsVisitor, visitor, v);

    GenericList **link;



    if (ov->repeated_opts_first) {

        ov->repeated_opts_first = false;

        link = list;

    } else {

        const QemuOpt *opt;



        opt = g_queue_pop_head(ov->repeated_opts);

        if (g_queue_is_empty(ov->repeated_opts)) {

            g_hash_table_remove(ov->unprocessed_opts, opt->name);

            return NULL;

        }

        link = &(*list)->next;

    }



    *link = g_malloc0(sizeof **link);

    return *link;

}
