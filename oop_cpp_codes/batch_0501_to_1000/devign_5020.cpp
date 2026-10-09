/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5020
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=079019f2e319bd1279681b6c1d7dde785d09e69e
 */

static void virt_machine_class_init(ObjectClass *oc, void *data)

{

    MachineClass *mc = MACHINE_CLASS(oc);



    mc->init = machvirt_init;

    /* Start max_cpus at the maximum QEMU supports. We'll further restrict

     * it later in machvirt_init, where we have more information about the

     * configuration of the particular instance.

     */

    mc->max_cpus = MAX_CPUMASK_BITS;

    mc->has_dynamic_sysbus = true;

    mc->block_default_type = IF_VIRTIO;

    mc->no_cdrom = 1;

    mc->pci_allow_0_address = true;

}
