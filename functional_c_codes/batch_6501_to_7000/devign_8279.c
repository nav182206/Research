/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8279
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d812b3d68ddf0efe91a088ecc8b177865b0bab8d
 */

static void port92_write(void *opaque, hwaddr addr, uint64_t val,

                         unsigned size)

{

    Port92State *s = opaque;

    int oldval = s->outport;



    DPRINTF("port92: write 0x%02" PRIx64 "\n", val);

    s->outport = val;

    qemu_set_irq(*s->a20_out, (val >> 1) & 1);

    if ((val & 1) && !(oldval & 1)) {

        qemu_system_reset_request();

    }

}
