/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_6393
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fd0a10cd20a1c5ae829be32f3364dae88f435c4e
 */

static void ohci_sof(OHCIState *ohci)

{

    ohci->sof_time = qemu_clock_get_ns(QEMU_CLOCK_VIRTUAL);

    timer_mod(ohci->eof_timer, ohci->sof_time + usb_frame_time);

    ohci_set_interrupt(ohci, OHCI_INTR_SF);

}
