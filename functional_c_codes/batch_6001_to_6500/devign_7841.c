/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7841
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=45bbbb466cf4a6280076ea5a51f67ef5bedee345
 */

void helper_idivq_EAX_T0(void)

{

    uint64_t r0, r1;

    if (T0 == 0) {

        raise_exception(EXCP00_DIVZ);

    }

    r0 = EAX;

    r1 = EDX;

    idiv64(&r0, &r1, T0);

    EAX = r0;

    EDX = r1;

}
