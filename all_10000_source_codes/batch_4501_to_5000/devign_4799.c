/* 
 * Benchmark Sample ID : devign_4799
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7c47959d0cb05db43014141a156ada0b6d53a750
 */

GList *g_list_insert_sorted_merged(GList *list, gpointer data,

                                   GCompareFunc func)

{

    GList *l, *next = NULL;

    Range *r, *nextr;



    if (!list) {

        list = g_list_insert_sorted(list, data, func);

        return list;

    }



    nextr = data;

    l = list;

    while (l && l != next && nextr) {

        r = l->data;

        if (ranges_can_merge(r, nextr)) {

            range_merge(r, nextr);

            l = g_list_remove_link(l, next);

            next = g_list_next(l);

            if (next) {

                nextr = next->data;

            } else {

                nextr = NULL;

            }

        } else {

            l = g_list_next(l);

        }

    }



    if (!l) {

        list = g_list_insert_sorted(list, data, func);

    }



    return list;

}
