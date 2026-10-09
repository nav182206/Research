/* 
 * Benchmark Sample ID : devign_7117
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e2779de053b64f023de382fd87b3596613d47d1e
 */

static int xen_pt_msgaddr32_reg_write(XenPCIPassthroughState *s,

                                      XenPTReg *cfg_entry, uint32_t *val,

                                      uint32_t dev_value, uint32_t valid_mask)

{

    XenPTRegInfo *reg = cfg_entry->reg;

    uint32_t writable_mask = 0;

    uint32_t old_addr = cfg_entry->data;



    /* modify emulate register */

    writable_mask = reg->emu_mask & ~reg->ro_mask & valid_mask;

    cfg_entry->data = XEN_PT_MERGE_VALUE(*val, cfg_entry->data, writable_mask);

    s->msi->addr_lo = cfg_entry->data;



    /* create value for writing to I/O device register */

    *val = XEN_PT_MERGE_VALUE(*val, dev_value, 0);



    /* update MSI */

    if (cfg_entry->data != old_addr) {

        if (s->msi->mapped) {

            xen_pt_msi_update(s);

        }

    }



    return 0;

}
