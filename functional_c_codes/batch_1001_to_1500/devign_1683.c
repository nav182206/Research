/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1683
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a5cf8262e4eb9c4646434e2c6211ef8608db3233
 */

static char *sysbus_get_fw_dev_path(DeviceState *dev)

{

    SysBusDevice *s = sysbus_from_qdev(dev);

    char path[40];

    int off;



    off = snprintf(path, sizeof(path), "%s", qdev_fw_name(dev));



    if (s->num_mmio) {

        snprintf(path + off, sizeof(path) - off, "@"TARGET_FMT_plx,

                 s->mmio[0].addr);

    } else if (s->num_pio) {

        snprintf(path + off, sizeof(path) - off, "@i%04x", s->pio[0]);

    }



    return strdup(path);

}
