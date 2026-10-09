/* 
 * Benchmark Sample ID : devign_1205
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d4551293d68a1876df87400be6c71c657756d0bb
 */

static int is_async_return(const QObject *data)

{

    if (data && qobject_type(data) == QTYPE_QDICT) {

        return qdict_haskey(qobject_to_qdict(data), "__mon_async");

    }



    return 0;

}
