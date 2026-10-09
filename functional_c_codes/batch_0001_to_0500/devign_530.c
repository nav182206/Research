/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_530
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=aec4b054ea36c53c8b887da99f20010133b84378
 */

static void limits_nesting(void)

{

    enum { max_nesting = 1024 }; /* see qobject/json-streamer.c */

    char buf[2 * (max_nesting + 1) + 1];

    QObject *obj;



    obj = qobject_from_json(make_nest(buf, max_nesting), NULL);

    g_assert(obj != NULL);

    qobject_decref(obj);



    obj = qobject_from_json(make_nest(buf, max_nesting + 1), NULL);

    g_assert(obj == NULL);

}
