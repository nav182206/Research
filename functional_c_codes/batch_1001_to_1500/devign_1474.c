/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1474
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9669d3c570c7a2129c6d6d4e32b856a2d155eb54
 */

void qemu_system_powerdown(void)

{

    if(pm_state->pmen & PWRBTN_EN) {

        pm_state->pmsts |= PWRBTN_EN;

	pm_update_sci(pm_state);

    }

}
