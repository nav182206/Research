/* 
 * Benchmark Sample ID : devign_7327
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e41b509d68afb1f329c8558b6edfe2fcbac88e66
 */

static void print_type_size(Visitor *v, uint64_t *obj, const char *name,

                           Error **errp)

{

    StringOutputVisitor *sov = DO_UPCAST(StringOutputVisitor, visitor, v);

    static const char suffixes[] = { 'B', 'K', 'M', 'G', 'T' };

    uint64_t div, val;

    char *out;

    int i;



    if (!sov->human) {

        out = g_strdup_printf("%llu", (long long) *obj);

        string_output_set(sov, out);

        return;

    }



    val = *obj;



    /* Compute floor(log2(val)).  */

    i = 64 - clz64(val);



    /* Find the power of 1024 that we'll display as the units.  */

    i /= 10;

    if (i >= ARRAY_SIZE(suffixes)) {

        i = ARRAY_SIZE(suffixes) - 1;

    }

    div = 1ULL << (i * 10);



    out = g_strdup_printf("%0.03f%c", (double)val/div, suffixes[i]);

    string_output_set(sov, out);

}
