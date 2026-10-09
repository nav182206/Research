/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6125
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c6fcb0e201ad296a9c0f587486830d9508094efb
 */

void kvm_ioapic_dump_state(Monitor *mon, const QDict *qdict)

{

    IOAPICCommonState s;



    kvm_ioapic_get(&s);



    ioapic_print_redtbl(mon, &s);

}
