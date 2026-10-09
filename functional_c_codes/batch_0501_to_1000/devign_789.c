/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_789
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=45fe15c25a5c9feea6e0f78434f5e9f632de9d94
 */

static int intel_hda_exit(PCIDevice *pci)

{

    IntelHDAState *d = DO_UPCAST(IntelHDAState, pci, pci);



    if (d->msi) {

        msi_uninit(&d->pci);

    }

    cpu_unregister_io_memory(d->mmio_addr);

    return 0;

}
