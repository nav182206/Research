/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3471
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=025b168ca674e42896c573fdbddf3090c6dc0d8f
 */

static void ehci_trace_qh(EHCIQueue *q, target_phys_addr_t addr, EHCIqh *qh)

{

    trace_usb_ehci_qh(q, addr, qh->next,

                      qh->current_qtd, qh->next_qtd, qh->altnext_qtd,

                      get_field(qh->epchar, QH_EPCHAR_RL),

                      get_field(qh->epchar, QH_EPCHAR_MPLEN),

                      get_field(qh->epchar, QH_EPCHAR_EPS),

                      get_field(qh->epchar, QH_EPCHAR_EP),

                      get_field(qh->epchar, QH_EPCHAR_DEVADDR),

                      (bool)(qh->epchar & QH_EPCHAR_C),

                      (bool)(qh->epchar & QH_EPCHAR_H),

                      (bool)(qh->epchar & QH_EPCHAR_DTC),

                      (bool)(qh->epchar & QH_EPCHAR_I));

}
