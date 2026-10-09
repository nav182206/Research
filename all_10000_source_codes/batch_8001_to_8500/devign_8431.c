/* 
 * Benchmark Sample ID : devign_8431
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=84fd9dd3f78ced9d41e1160d43862bb620cb462a
 */

void tcg_register_helper(void *func, const char *name)

{

    TCGContext *s = &tcg_ctx;

    GHashTable *table = s->helpers;



    if (table == NULL) {

        /* Use g_direct_hash/equal for direct pointer comparisons on func.  */

        table = g_hash_table_new(NULL, NULL);

        s->helpers = table;

    }



    g_hash_table_insert(table, (gpointer)func, (gpointer)name);

}
