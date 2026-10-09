/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5149
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=da98c8eb4c35225049cad8cf767647eb39788b5d
 */

void acpi_pm1_cnt_reset(ACPIREGS *ar)

{

    ar->pm1.cnt.cnt = 0;

    if (ar->pm1.cnt.cmos_s3) {

        qemu_irq_lower(ar->pm1.cnt.cmos_s3);

    }

}
