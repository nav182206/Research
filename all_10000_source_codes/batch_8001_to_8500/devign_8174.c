/* 
 * Benchmark Sample ID : devign_8174
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e17a87792d4886d2a508672c1639df3c1d40f1d1
 */

char *spapr_get_cpu_core_type(const char *model)

{

    char *core_type;

    gchar **model_pieces = g_strsplit(model, ",", 2);



    core_type = g_strdup_printf("%s-%s", model_pieces[0], TYPE_SPAPR_CPU_CORE);

    g_strfreev(model_pieces);



    /* Check whether it exists or whether we have to look up an alias name */

    if (!object_class_by_name(core_type)) {

        const char *realmodel;



        g_free(core_type);

        realmodel = ppc_cpu_lookup_alias(model);

        if (realmodel) {

            return spapr_get_cpu_core_type(realmodel);

        }

        return NULL;

    }



    return core_type;

}
