/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8875
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e654887f3880fb0f6d4d40d15d2977de245a6440
 */

static void ehci_trace_itd(EHCIState *s, target_phys_addr_t addr, EHCIitd *itd)

{

    trace_usb_ehci_itd(addr, itd->next);

}
