/* 
 * Benchmark Sample ID : devign_35
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=456d97d364e34adc4e68cbd51c2ad6ecd548492d
 */

void hmp_info_io_apic(Monitor *mon, const QDict *qdict)

{

    if (kvm_irqchip_in_kernel()) {

        kvm_ioapic_dump_state(mon, qdict);

    } else {

        ioapic_dump_state(mon, qdict);

    }

}
