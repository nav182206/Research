/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4003
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a89f364ae8740dfc31b321eed9ee454e996dc3c1
 */

static int tosa_dac_event(I2CSlave *i2c, enum i2c_event event)

{

    TosaDACState *s = TOSA_DAC(i2c);



    s->len = 0;

    switch (event) {

    case I2C_START_SEND:

        break;

    case I2C_START_RECV:

        printf("%s: recv not supported!!!\n", __FUNCTION__);

        break;

    case I2C_FINISH:

#ifdef VERBOSE

        if (s->len < 2)

            printf("%s: message too short (%i bytes)\n", __FUNCTION__, s->len);

        if (s->len > 2)

            printf("%s: message too long\n", __FUNCTION__);

#endif

        break;

    default:

        break;

    }



    return 0;

}
