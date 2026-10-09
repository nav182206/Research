/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1196
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=aec4b054ea36c53c8b887da99f20010133b84378
 */

static void invalid_dict_comma(void)

{

    QObject *obj = qobject_from_json("{'abc':32,}", NULL);

    g_assert(obj == NULL);

}
