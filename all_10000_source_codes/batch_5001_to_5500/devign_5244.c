/* 
 * Benchmark Sample ID : devign_5244
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=aec4b054ea36c53c8b887da99f20010133b84378
 */

static void unterminated_string(void)

{

    QObject *obj = qobject_from_json("\"abc", NULL);

    g_assert(obj == NULL);

}
