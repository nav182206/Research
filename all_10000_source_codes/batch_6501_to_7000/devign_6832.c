/* 
 * Benchmark Sample ID : devign_6832
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2bd01ac1e238c76e201ba21f314cec46437d2c5a
 */

static void string_deserialize(void **native_out, void *datap,

                               VisitorFunc visit, Error **errp)

{

    StringSerializeData *d = datap;



    d->siv = string_input_visitor_new(string_output_get_string(d->sov));

    visit(string_input_get_visitor(d->siv), native_out, errp);

}
