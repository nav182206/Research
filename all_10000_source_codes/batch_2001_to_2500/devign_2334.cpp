/* 
 * Benchmark Sample ID : devign_2334
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e4e05b7b3e28970bcb9c0032dc46e30950e75f18
 */

static void fsl_imx31_class_init(ObjectClass *oc, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(oc);



    dc->realize = fsl_imx31_realize;



    dc->desc = "i.MX31 SOC";

}
