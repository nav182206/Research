/* 
 * Benchmark Sample ID : devign_4280
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e2779de053b64f023de382fd87b3596613d47d1e
 */

static int xen_pt_word_reg_write(XenPCIPassthroughState *s, XenPTReg *cfg_entry,

                                 uint16_t *val, uint16_t dev_value,

                                 uint16_t valid_mask)

{

    XenPTRegInfo *reg = cfg_entry->reg;

    uint16_t writable_mask = 0;

    uint16_t throughable_mask = get_throughable_mask(s, reg, valid_mask);



    /* modify emulate register */

    writable_mask = reg->emu_mask & ~reg->ro_mask & valid_mask;

    cfg_entry->data = XEN_PT_MERGE_VALUE(*val, cfg_entry->data, writable_mask);



    /* create value for writing to I/O device register */

    *val = XEN_PT_MERGE_VALUE(*val, dev_value, throughable_mask);



    return 0;

}
