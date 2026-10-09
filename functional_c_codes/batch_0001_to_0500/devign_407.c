/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_407
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d9f62dde1303286b24ac8ce88be27e2b9b9c5f46
 */

GenericList *visit_next_list(Visitor *v, GenericList **list, size_t size)

{

    assert(list && size >= sizeof(GenericList));

    return v->next_list(v, list, size);

}
