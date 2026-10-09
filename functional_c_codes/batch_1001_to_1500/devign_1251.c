/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1251
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=aeb23fc4549a25ef32ff085d2a76227f90caf403
 */

static void ini_print_object_header(const char *name)

{

    int i;

    PrintElement *el = octx.prefix + octx.level -1;



    if (el->nb_elems)

        avio_printf(probe_out, "\n");



    avio_printf(probe_out, "[");



    for (i = 1; i < octx.level; i++) {

        el = octx.prefix + i;

        avio_printf(probe_out, "%s.", el->name);

        if (el->index >= 0)

            avio_printf(probe_out, "%"PRId64".", el->index);

    }



    avio_printf(probe_out, "%s", name);

    if (el && el->type == ARRAY)

        avio_printf(probe_out, ".%"PRId64"", el->nb_elems);

    avio_printf(probe_out, "]\n");

}
