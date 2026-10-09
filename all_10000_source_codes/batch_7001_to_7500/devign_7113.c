/* 
 * Benchmark Sample ID : devign_7113
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7c47959d0cb05db43014141a156ada0b6d53a750
 */

static void string_output_append(StringOutputVisitor *sov, int64_t a)

{

    Range *r = g_malloc0(sizeof(*r));

    r->begin = a;

    r->end = a + 1;

    sov->ranges = g_list_insert_sorted_merged(sov->ranges, r, range_compare);

}
