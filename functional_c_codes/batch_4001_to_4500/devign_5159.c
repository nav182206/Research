/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5159
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3b098d56979d2f7fd707c5be85555d114353a28d
 */

static void string_cleanup(void *datap)

{

    StringSerializeData *d = datap;



    visit_free(string_output_get_visitor(d->sov));

    visit_free(d->siv);

    g_free(d->string);

    g_free(d);

}
