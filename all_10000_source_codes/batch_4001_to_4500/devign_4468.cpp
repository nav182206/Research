/* 
 * Benchmark Sample ID : devign_4468
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=65a8e1f6413a0f6f79894da710b5d6d43361d27d
 */

size_t mptsas_config_ioc_0(MPTSASState *s, uint8_t **data, int address)

{

    PCIDeviceClass *pcic = PCI_DEVICE_GET_CLASS(s);



    return MPTSAS_CONFIG_PACK(0, MPI_CONFIG_PAGETYPE_IOC, 0x01,

                              "*l*lwwb*b*b*blww",

                              pcic->vendor_id, pcic->device_id, pcic->revision,

                              pcic->subsystem_vendor_id,

                              pcic->subsystem_id);

}
