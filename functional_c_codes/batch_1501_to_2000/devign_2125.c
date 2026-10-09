/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2125
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7d5e199ade76c53ec316ab6779800581bb47c50a
 */

static GenericList *qmp_output_next_list(Visitor *v, GenericList *tail,

                                         size_t size)

{

    return tail->next;

}
