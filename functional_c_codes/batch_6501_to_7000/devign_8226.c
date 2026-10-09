/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8226
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cda607d5e0178d0268066d94dd06b89614304a7d
 */

static void set_fifodepth(MSSSpiState *s)

{

    unsigned int size = s->regs[R_SPI_DFSIZE] & FRAMESZ_MASK;



    if (size <= 8) {

        s->fifo_depth = 32;

    } else if (size <= 16) {

        s->fifo_depth = 16;

    } else if (size <= 32) {

        s->fifo_depth = 8;

    } else {

        s->fifo_depth = 4;

    }

}
