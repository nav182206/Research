/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3628
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e7d336959b7c01699702dcda4b54a822972d74a8
 */

int chsc_sei_nt2_have_event(void)

{

    S390pciState *s = S390_PCI_HOST_BRIDGE(

        object_resolve_path(TYPE_S390_PCI_HOST_BRIDGE, NULL));



    if (!s) {

        return 0;

    }



    return !QTAILQ_EMPTY(&s->pending_sei);

}
