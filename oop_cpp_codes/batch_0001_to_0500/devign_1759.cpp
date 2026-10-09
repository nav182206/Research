/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_1759
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=01960e6d21dcfbfc8a03d8fd6284c448cf75865b
 */

int kvm_arch_release_virq_post(int virq)

{

    MSIRouteEntry *entry, *next;

    QLIST_FOREACH_SAFE(entry, &msi_route_list, list, next) {

        if (entry->virq == virq) {

            trace_kvm_x86_remove_msi_route(virq);

            QLIST_REMOVE(entry, list);


            break;

        }

    }

    return 0;

}
