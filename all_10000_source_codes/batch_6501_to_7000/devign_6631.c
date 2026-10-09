/* 
 * Benchmark Sample ID : devign_6631
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a89f364ae8740dfc31b321eed9ee454e996dc3c1
 */

static int wm8750_event(I2CSlave *i2c, enum i2c_event event)

{

    WM8750State *s = WM8750(i2c);



    switch (event) {

    case I2C_START_SEND:

        s->i2c_len = 0;

        break;

    case I2C_FINISH:

#ifdef VERBOSE

        if (s->i2c_len < 2)

            printf("%s: message too short (%i bytes)\n",

                            __FUNCTION__, s->i2c_len);

#endif

        break;

    default:

        break;

    }



    return 0;

}
