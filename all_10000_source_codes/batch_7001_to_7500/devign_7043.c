/* 
 * Benchmark Sample ID : devign_7043
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a426e122173f36f05ea2cb72dcff77b7408546ce
 */

static int kvm_client_sync_dirty_bitmap(struct CPUPhysMemoryClient *client,

					target_phys_addr_t start_addr,

					target_phys_addr_t end_addr)

{

	return kvm_physical_sync_dirty_bitmap(start_addr, end_addr);

}
