/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2267
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3b098d56979d2f7fd707c5be85555d114353a28d
 */

static void string_deserialize(void **native_out, void *datap,

                               VisitorFunc visit, Error **errp)

{

    StringSerializeData *d = datap;



    d->string = string_output_get_string(d->sov);

    d->siv = string_input_visitor_new(d->string);

    visit(d->siv, native_out, errp);

}
