/* 
 * Benchmark Sample ID : devign_1864
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c7f8d0f3a52b5ef8fdcd305cce438f67d7e06a9f
 */

static void pc_dimm_post_plug(HotplugHandler *hotplug_dev,

                              DeviceState *dev, Error **errp)

{

    PCMachineState *pcms = PC_MACHINE(hotplug_dev);



    if (object_dynamic_cast(OBJECT(dev), TYPE_NVDIMM)) {

        nvdimm_acpi_hotplug(&pcms->acpi_nvdimm_state);

    }

}
