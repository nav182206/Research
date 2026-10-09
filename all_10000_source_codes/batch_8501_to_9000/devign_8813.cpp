/* 
 * Benchmark Sample ID : devign_8813
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1beb99f787ba110a9de44254e7d62a1cb9117de8
 */

void acpi_pm_tmr_init(ACPIREGS *ar, acpi_update_sci_fn update_sci,

                      MemoryRegion *parent)

{

    ar->tmr.update_sci = update_sci;

    ar->tmr.timer = timer_new_ns(QEMU_CLOCK_VIRTUAL, acpi_pm_tmr_timer, ar);

    memory_region_init_io(&ar->tmr.io, memory_region_owner(parent),

                          &acpi_pm_tmr_ops, ar, "acpi-tmr", 4);

    memory_region_clear_global_locking(&ar->tmr.io);

    memory_region_add_subregion(parent, 8, &ar->tmr.io);

}
