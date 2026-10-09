/* 
 * Benchmark Sample ID : devign_240
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=de00982e9e14e2d6ba3d148f02c5a1e94deaa985
 */

static void xen_platform_ioport_writeb(void *opaque, uint32_t addr, uint32_t val)

{

    PCIXenPlatformState *s = opaque;



    addr &= 0xff;

    val  &= 0xff;



    switch (addr) {

    case 0: /* Platform flags */

        platform_fixed_ioport_writeb(opaque, XEN_PLATFORM_IOPORT, val);

        break;

    case 8:

        log_writeb(s, val);

        break;

    default:

        break;

    }

}
