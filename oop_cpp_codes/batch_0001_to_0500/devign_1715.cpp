/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_1715
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=089da572b956ef0f8f5b8d5917358e07892a77c2
 */

void fw_cfg_add_bytes(FWCfgState *s, uint16_t key, uint8_t *data, uint32_t len)

{

    int arch = !!(key & FW_CFG_ARCH_LOCAL);



    key &= FW_CFG_ENTRY_MASK;



    assert(key < FW_CFG_MAX_ENTRY);



    s->entries[arch][key].data = data;

    s->entries[arch][key].len = len;

}
