/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_8741
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9be385980d37e8f4fd33f605f5fb1c3d144170a8
 */

static char *spapr_vio_get_dev_name(DeviceState *qdev)

{

    VIOsPAPRDevice *dev = VIO_SPAPR_DEVICE(qdev);

    VIOsPAPRDeviceClass *pc = VIO_SPAPR_DEVICE_GET_CLASS(dev);

    char *name;



    /* Device tree style name device@reg */

    name = g_strdup_printf("%s@%x", pc->dt_name, dev->reg);



    return name;

}
