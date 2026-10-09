/* 
 * Benchmark Sample ID : devign_5778
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2886be1b01c274570fa139748a402207482405bd
 */

uint16_t acpi_pm1_evt_get_sts(ACPIREGS *ar, int64_t overflow_time)

{

    int64_t d = acpi_pm_tmr_get_clock();

    if (d >= overflow_time) {

        ar->pm1.evt.sts |= ACPI_BITMASK_TIMER_STATUS;

    }

    return ar->pm1.evt.sts;

}
