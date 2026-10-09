/* 
 * Benchmark Sample ID : devign_9086
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5cd5e7015962d8d559afb5154888fd34a8526ddd
 */

void shpc_cleanup(PCIDevice *d, MemoryRegion *bar)

{

    SHPCDevice *shpc = d->shpc;

    d->cap_present &= ~QEMU_PCI_CAP_SHPC;

    memory_region_del_subregion(bar, &shpc->mmio);

    object_unparent(OBJECT(&shpc->mmio));

    /* TODO: cleanup config space changes? */

    g_free(shpc->config);

    g_free(shpc->cmask);

    g_free(shpc->wmask);

    g_free(shpc->w1cmask);

    g_free(shpc);

}
