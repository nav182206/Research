/* 
 * Benchmark Sample ID : devign_5372
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5e39d89d20b17cf6fb7f09d181d34f17b2ae2160
 */

static QList *get_cpus(QDict **resp)

{

    *resp = qmp("{ 'execute': 'query-cpus' }");

    g_assert(*resp);

    g_assert(qdict_haskey(*resp, "return"));

    return  qdict_get_qlist(*resp, "return");

}
