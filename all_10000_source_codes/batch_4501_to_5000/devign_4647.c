/* 
 * Benchmark Sample ID : devign_4647
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ab902981cf4d46834d82eb095f2b9ab159e017bf
 */

static void interface_set_client_capabilities(QXLInstance *sin,
                                              uint8_t client_present,
                                              uint8_t caps[58])
{
    PCIQXLDevice *qxl = container_of(sin, PCIQXLDevice, ssd.qxl);
    qxl->shadow_rom.client_present = client_present;
    memcpy(qxl->shadow_rom.client_capabilities, caps, sizeof(caps));
    qxl->rom->client_present = client_present;
    memcpy(qxl->rom->client_capabilities, caps, sizeof(caps));
    qxl_rom_set_dirty(qxl);
    qxl_send_events(qxl, QXL_INTERRUPT_CLIENT);
