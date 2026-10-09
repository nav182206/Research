/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_118
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a01672d3968cf91208666d371784110bfde9d4f8
 */

static int kvm_log_stop(CPUPhysMemoryClient *client,

                        target_phys_addr_t phys_addr, ram_addr_t size)

{

    return kvm_dirty_pages_log_change(phys_addr, size, false);

}
