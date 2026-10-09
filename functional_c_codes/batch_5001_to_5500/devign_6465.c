/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6465
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a89f364ae8740dfc31b321eed9ee454e996dc3c1
 */

static uint64_t pxa2xx_i2c_read(void *opaque, hwaddr addr,

                                unsigned size)

{

    PXA2xxI2CState *s = (PXA2xxI2CState *) opaque;

    I2CSlave *slave;



    addr -= s->offset;

    switch (addr) {

    case ICR:

        return s->control;

    case ISR:

        return s->status | (i2c_bus_busy(s->bus) << 2);

    case ISAR:

        slave = I2C_SLAVE(s->slave);

        return slave->address;

    case IDBR:

        return s->data;

    case IBMR:

        if (s->status & (1 << 2))

            s->ibmr ^= 3;	/* Fake SCL and SDA pin changes */

        else

            s->ibmr = 0;

        return s->ibmr;

    default:

        printf("%s: Bad register " REG_FMT "\n", __FUNCTION__, addr);

        break;

    }

    return 0;

}
