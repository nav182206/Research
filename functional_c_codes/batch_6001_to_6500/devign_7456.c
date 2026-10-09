/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7456
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=786a4ea82ec9c87e3a895cf41081029b285a5fe5
 */

static uint16_t shpc_get_status(SHPCDevice *shpc, int slot, uint16_t msk)

{

    uint8_t *status = shpc->config + SHPC_SLOT_STATUS(slot);

    return (pci_get_word(status) & msk) >> (ffs(msk) - 1);

}
