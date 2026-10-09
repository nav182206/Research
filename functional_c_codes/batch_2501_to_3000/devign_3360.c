/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3360
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1195fed9e6790bd8fd86b0dc33e2442d70355ac6
 */

set_mdic(E1000State *s, int index, uint32_t val)

{

    uint32_t data = val & E1000_MDIC_DATA_MASK;

    uint32_t addr = ((val & E1000_MDIC_REG_MASK) >> E1000_MDIC_REG_SHIFT);



    if ((val & E1000_MDIC_PHY_MASK) >> E1000_MDIC_PHY_SHIFT != 1) // phy #

        val = s->mac_reg[MDIC] | E1000_MDIC_ERROR;

    else if (val & E1000_MDIC_OP_READ) {

        DBGOUT(MDIC, "MDIC read reg 0x%x\n", addr);

        if (!(phy_regcap[addr] & PHY_R)) {

            DBGOUT(MDIC, "MDIC read reg %x unhandled\n", addr);

            val |= E1000_MDIC_ERROR;

        } else

            val = (val ^ data) | s->phy_reg[addr];

    } else if (val & E1000_MDIC_OP_WRITE) {

        DBGOUT(MDIC, "MDIC write reg 0x%x, value 0x%x\n", addr, data);

        if (!(phy_regcap[addr] & PHY_W)) {

            DBGOUT(MDIC, "MDIC write reg %x unhandled\n", addr);

            val |= E1000_MDIC_ERROR;

        } else {

            if (addr < NPHYWRITEOPS && phyreg_writeops[addr]) {

                phyreg_writeops[addr](s, index, data);

            }

            s->phy_reg[addr] = data;

        }

    }

    s->mac_reg[MDIC] = val | E1000_MDIC_READY;



    if (val & E1000_MDIC_INT_EN) {

        set_ics(s, 0, E1000_ICR_MDAC);

    }

}
