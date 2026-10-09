/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1951
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=089da572b956ef0f8f5b8d5917358e07892a77c2
 */

void fw_cfg_add_i16(FWCfgState *s, uint16_t key, uint16_t value)

{

    uint16_t *copy;



    copy = g_malloc(sizeof(value));

    *copy = cpu_to_le16(value);

    fw_cfg_add_bytes(s, key, (uint8_t *)copy, sizeof(value));

}
