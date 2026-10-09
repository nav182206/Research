/* 
 * Benchmark Sample ID : devign_430
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7ec7ae4b973d1471f6f39fc2b6481f69c2b39593
 */

e1000e_cleanup_msix(E1000EState *s)

{

    if (msix_enabled(PCI_DEVICE(s))) {

        e1000e_unuse_msix_vectors(s, E1000E_MSIX_VEC_NUM);

        msix_uninit(PCI_DEVICE(s), &s->msix, &s->msix);

    }

}
