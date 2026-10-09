/* 
 * Benchmark Sample ID : devign_709
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e2779de053b64f023de382fd87b3596613d47d1e
 */

static int xen_pt_byte_reg_read(XenPCIPassthroughState *s, XenPTReg *cfg_entry,

                                uint8_t *value, uint8_t valid_mask)

{

    XenPTRegInfo *reg = cfg_entry->reg;

    uint8_t valid_emu_mask = 0;



    /* emulate byte register */

    valid_emu_mask = reg->emu_mask & valid_mask;

    *value = XEN_PT_MERGE_VALUE(*value, cfg_entry->data, ~valid_emu_mask);



    return 0;

}
