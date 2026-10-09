/* 
 * Benchmark Sample ID : devign_9377
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d812b3d68ddf0efe91a088ecc8b177865b0bab8d
 */

static void port92_init(ISADevice *dev, qemu_irq *a20_out)

{

    Port92State *s = PORT92(dev);



    s->a20_out = a20_out;

}
