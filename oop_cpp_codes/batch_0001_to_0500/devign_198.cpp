/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_198
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=34f2af3d3edf9d57c27811d3780cbc0ece319625
 */

static XICSState *try_create_xics(const char *type, int nr_servers,

                                  int nr_irqs)

{

    DeviceState *dev;



    dev = qdev_create(NULL, type);

    qdev_prop_set_uint32(dev, "nr_servers", nr_servers);

    qdev_prop_set_uint32(dev, "nr_irqs", nr_irqs);

    if (qdev_init(dev) < 0) {

        return NULL;

    }



    return XICS_COMMON(dev);

}
