/* 
 * Benchmark Sample ID : devign_1596
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=898248a32915024a4f01ce4f0c3519509fb703cb
 */

static bool xhci_er_full(void *opaque, int version_id)

{

    struct XHCIInterrupter *intr = opaque;

    return intr->er_full;

}
