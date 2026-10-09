/* 
 * Benchmark Sample ID : devign_3749
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a0efbf16604770b9d805bcf210ec29942321134f
 */

static void string_output_append_range(StringOutputVisitor *sov,

                                       int64_t s, int64_t e)

{

    Range *r = g_malloc0(sizeof(*r));

    r->begin = s;

    r->end = e + 1;

    sov->ranges = range_list_insert(sov->ranges, r);

}
