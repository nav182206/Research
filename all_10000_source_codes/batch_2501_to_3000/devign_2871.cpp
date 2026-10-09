/* 
 * Benchmark Sample ID : devign_2871
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6acbe4c6f18e7de00481ff30574262b58526de45
 */

const char *qdev_fw_name(DeviceState *dev)

{

    DeviceClass *dc = DEVICE_GET_CLASS(dev);



    if (dc->fw_name) {

        return dc->fw_name;

    } else if (dc->alias) {

        return dc->alias;

    }



    return object_get_typename(OBJECT(dev));

}
