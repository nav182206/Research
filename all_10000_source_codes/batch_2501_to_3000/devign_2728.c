/* 
 * Benchmark Sample ID : devign_2728
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d9f62dde1303286b24ac8ce88be27e2b9b9c5f46
 */

start_list(Visitor *v, const char *name, Error **errp)

{

    StringInputVisitor *siv = to_siv(v);



    if (parse_str(siv, name, errp) < 0) {

        return;

    }



    siv->cur_range = g_list_first(siv->ranges);

    if (siv->cur_range) {

        Range *r = siv->cur_range->data;

        if (r) {

            siv->cur = r->begin;

        }

    }

}
