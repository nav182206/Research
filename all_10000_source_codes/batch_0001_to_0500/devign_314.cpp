/* 
 * Benchmark Sample ID : devign_314
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c25a67f0c3d0c86231f9653267a222c4effa706f
 */

static void pci_edu_realize(PCIDevice *pdev, Error **errp)

{

    EduState *edu = DO_UPCAST(EduState, pdev, pdev);

    uint8_t *pci_conf = pdev->config;



    timer_init_ms(&edu->dma_timer, QEMU_CLOCK_VIRTUAL, edu_dma_timer, edu);



    qemu_mutex_init(&edu->thr_mutex);

    qemu_cond_init(&edu->thr_cond);

    qemu_thread_create(&edu->thread, "edu", edu_fact_thread,

                       edu, QEMU_THREAD_JOINABLE);



    pci_config_set_interrupt_pin(pci_conf, 1);



    if (msi_init(pdev, 0, 1, true, false, errp)) {

        return;

    }



    memory_region_init_io(&edu->mmio, OBJECT(edu), &edu_mmio_ops, edu,

                    "edu-mmio", 1 << 20);

    pci_register_bar(pdev, 0, PCI_BASE_ADDRESS_SPACE_MEMORY, &edu->mmio);

}
