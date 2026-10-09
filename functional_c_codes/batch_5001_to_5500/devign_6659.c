/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6659
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a0efbf16604770b9d805bcf210ec29942321134f
 */

static void string_output_append(StringOutputVisitor *sov, int64_t a)

{

    Range *r = g_malloc0(sizeof(*r));

    r->begin = a;

    r->end = a + 1;

    sov->ranges = range_list_insert(sov->ranges, r);

}
