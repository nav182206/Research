/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4888
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fba72476c6b7be60ac74c5bcdc06c61242d1fe4f
 */

static void pm_reset(void *opaque)

{

    ICH9LPCPMRegs *pm = opaque;

    ich9_pm_iospace_update(pm, 0);



    acpi_pm1_evt_reset(&pm->acpi_regs);

    acpi_pm1_cnt_reset(&pm->acpi_regs);

    acpi_pm_tmr_reset(&pm->acpi_regs);

    acpi_gpe_reset(&pm->acpi_regs);



    if (kvm_enabled()) {

        /* Mark SMM as already inited to prevent SMM from running. KVM does not

         * support SMM mode. */

        pm->smi_en |= ICH9_PMIO_SMI_EN_APMC_EN;

    }

    pm->smi_en_wmask = ~0;



    acpi_update_sci(&pm->acpi_regs, pm->irq);

}
