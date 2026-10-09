/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6967
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9be385980d37e8f4fd33f605f5fb1c3d144170a8
 */

static uint32_t vbe_ioport_read_index(void *opaque, uint32_t addr)

{

    VGACommonState *s = opaque;

    uint32_t val;

    val = s->vbe_index;

    return val;

}
