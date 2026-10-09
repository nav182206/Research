/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8652
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e23a1b33b53d25510320b26d9f154e19c6c99725
 */

static DeviceState *sbi_init(target_phys_addr_t addr, qemu_irq **parent_irq)

{

    DeviceState *dev;

    SysBusDevice *s;

    unsigned int i;



    dev = qdev_create(NULL, "sbi");

    qdev_init(dev);



    s = sysbus_from_qdev(dev);



    for (i = 0; i < MAX_CPUS; i++) {

        sysbus_connect_irq(s, i, *parent_irq[i]);

    }



    sysbus_mmio_map(s, 0, addr);



    return dev;

}
