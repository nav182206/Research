/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5294
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=688b057aece53003f9d5a1dadc8961482dc2d948
 */

void qdev_init_gpio_out_named(DeviceState *dev, qemu_irq *pins,
                              const char *name, int n)
{
    NamedGPIOList *gpio_list = qdev_get_named_gpio_list(dev, name);
    assert(gpio_list->num_in == 0 || !name);
    assert(gpio_list->num_out == 0);
    gpio_list->num_out = n;
    gpio_list->out = pins;
