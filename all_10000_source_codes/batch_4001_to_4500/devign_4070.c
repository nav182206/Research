/* 
 * Benchmark Sample ID : devign_4070
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=37f51384ae05bd50f83308339dbffa3e78404874
 */

static void vtd_root_table_setup(IntelIOMMUState *s)

{

    s->root = vtd_get_quad_raw(s, DMAR_RTADDR_REG);

    s->root_extended = s->root & VTD_RTADDR_RTT;

    s->root &= VTD_RTADDR_ADDR_MASK(VTD_HOST_ADDRESS_WIDTH);



    trace_vtd_reg_dmar_root(s->root, s->root_extended);

}
