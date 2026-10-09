/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3762
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0919ac787641db11024912651f3bc5764d4f1286
 */

static void n8x0_i2c_setup(struct n800_s *s)

{

    DeviceState *dev;

    qemu_irq tmp_irq = qdev_get_gpio_in(s->cpu->gpio, N8X0_TMP105_GPIO);



    /* Attach the CPU on one end of our I2C bus.  */

    s->i2c = omap_i2c_bus(s->cpu->i2c[0]);



    /* Attach a menelaus PM chip */

    dev = i2c_create_slave(s->i2c, "twl92230", N8X0_MENELAUS_ADDR);

    qdev_connect_gpio_out(dev, 3, s->cpu->irq[0][OMAP_INT_24XX_SYS_NIRQ]);



    /* Attach a TMP105 PM chip (A0 wired to ground) */

    dev = i2c_create_slave(s->i2c, "tmp105", N8X0_TMP105_ADDR);

    qdev_connect_gpio_out(dev, 0, tmp_irq);

}
