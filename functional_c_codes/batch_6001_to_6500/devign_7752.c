/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7752
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e1f8c729fa890c67bb4532f22c22ace6fb0e1aaf
 */

DeviceState *pxa2xx_gpio_init(target_phys_addr_t base,

                CPUState *env, qemu_irq *pic, int lines)

{

    DeviceState *dev;



    dev = qdev_create(NULL, "pxa2xx-gpio");

    qdev_prop_set_int32(dev, "lines", lines);

    qdev_prop_set_int32(dev, "ncpu", env->cpu_index);

    qdev_init_nofail(dev);



    sysbus_mmio_map(sysbus_from_qdev(dev), 0, base);

    sysbus_connect_irq(sysbus_from_qdev(dev), 0, pic[PXA2XX_PIC_GPIO_0]);

    sysbus_connect_irq(sysbus_from_qdev(dev), 1, pic[PXA2XX_PIC_GPIO_1]);

    sysbus_connect_irq(sysbus_from_qdev(dev), 2, pic[PXA2XX_PIC_GPIO_X]);



    return dev;

}
