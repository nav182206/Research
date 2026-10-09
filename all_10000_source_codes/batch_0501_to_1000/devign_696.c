/* 
 * Benchmark Sample ID : devign_696
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e864cabdc0a38bb598ddcf88b264896dc6f3e3b2
 */

void do_fctiw (void)

{

    union {

        double d;

        uint64_t i;

    } p;



    /* XXX: higher bits are not supposed to be significant.

     *     to make tests easier, return the same as a real PowerPC 750 (aka G3)

     */

    p.i = float64_to_int32(FT0, &env->fp_status);

    p.i |= 0xFFF80000ULL << 32;

    FT0 = p.d;

}
