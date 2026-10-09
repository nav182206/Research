/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_8923
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=53111180946a56d314a9c1d07d09b9ef91e847b9
 */

static void armv7m_nvic_class_init(ObjectClass *klass, void *data)

{

    NVICClass *nc = NVIC_CLASS(klass);

    DeviceClass *dc = DEVICE_CLASS(klass);

    SysBusDeviceClass *sdc = SYS_BUS_DEVICE_CLASS(klass);



    nc->parent_reset = dc->reset;

    nc->parent_init = sdc->init;

    sdc->init = armv7m_nvic_init;

    dc->vmsd  = &vmstate_nvic;

    dc->reset = armv7m_nvic_reset;

}
