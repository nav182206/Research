/* 
 * Benchmark Sample ID : devign_3148
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=68d553587c0aa271c3eb2902921b503740d775b6
 */

static void ehci_flush_qh(EHCIQueue *q)

{

    uint32_t *qh = (uint32_t *) &q->qh;

    uint32_t dwords = sizeof(EHCIqh) >> 2;

    uint32_t addr = NLPTR_GET(q->qhaddr);



    put_dwords(addr + 3 * sizeof(uint32_t), qh + 3, dwords - 3);

}
