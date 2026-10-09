/* 
 * Benchmark Sample ID : devign_8802
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e23a1b33b53d25510320b26d9f154e19c6c99725
 */

static void apc_init(target_phys_addr_t power_base, qemu_irq cpu_halt)

{

    DeviceState *dev;

    SysBusDevice *s;



    dev = qdev_create(NULL, "apc");

    qdev_init(dev);

    s = sysbus_from_qdev(dev);

    /* Power management (APC) XXX: not a Slavio device */

    sysbus_mmio_map(s, 0, power_base);

    sysbus_connect_irq(s, 0, cpu_halt);

}
