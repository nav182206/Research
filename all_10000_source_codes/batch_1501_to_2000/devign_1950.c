/* 
 * Benchmark Sample ID : devign_1950
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=74f24cb6306d065045d0e2215a7d10533fa59c57
 */

start_list(Visitor *v, const char *name, Error **errp)

{

    StringInputVisitor *siv = to_siv(v);



    parse_str(siv, errp);



    siv->cur_range = g_list_first(siv->ranges);

    if (siv->cur_range) {

        Range *r = siv->cur_range->data;

        if (r) {

            siv->cur = r->begin;

        }

    }

}
