/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_8057
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1195fed9e6790bd8fd86b0dc33e2442d70355ac6
 */

set_phy_ctrl(E1000State *s, int index, uint16_t val)

{

    /*

     * QEMU 1.3 does not support link auto-negotiation emulation, so if we

     * migrate during auto negotiation, after migration the link will be

     * down.

     */

    if (!(s->compat_flags & E1000_FLAG_AUTONEG)) {

        return;

    }

    if ((val & MII_CR_AUTO_NEG_EN) && (val & MII_CR_RESTART_AUTO_NEG)) {

        e1000_link_down(s);

        DBGOUT(PHY, "Start link auto negotiation\n");

        timer_mod(s->autoneg_timer, qemu_clock_get_ms(QEMU_CLOCK_VIRTUAL) + 500);

    }

}
