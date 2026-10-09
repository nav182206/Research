/* 
 * Benchmark Sample ID : devign_8624
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4482e05cbbb7e50e476f6a9500cf0b38913bd939
 */

const char *cpu_parse_cpu_model(const char *typename, const char *cpu_model)

{

    ObjectClass *oc;

    CPUClass *cc;

    Error *err = NULL;

    gchar **model_pieces;

    const char *cpu_type;



    model_pieces = g_strsplit(cpu_model, ",", 2);



    oc = cpu_class_by_name(typename, model_pieces[0]);

    if (oc == NULL) {

        g_strfreev(model_pieces);

        return NULL;

    }



    cpu_type = object_class_get_name(oc);

    cc = CPU_CLASS(oc);

    cc->parse_features(cpu_type, model_pieces[1], &err);

    g_strfreev(model_pieces);

    if (err != NULL) {

        error_report_err(err);

        return NULL;

    }

    return cpu_type;

}
