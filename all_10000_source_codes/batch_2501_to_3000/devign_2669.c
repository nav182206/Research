/* 
 * Benchmark Sample ID : devign_2669
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=100f738850639a108d6767316ce4dcc1d1ea4ae4
 */

static void ics_kvm_realize(DeviceState *dev, Error **errp)

{

    ICSState *ics = ICS_SIMPLE(dev);



    if (!ics->nr_irqs) {

        error_setg(errp, "Number of interrupts needs to be greater 0");

        return;

    }

    ics->irqs = g_malloc0(ics->nr_irqs * sizeof(ICSIRQState));

    ics->qirqs = qemu_allocate_irqs(ics_kvm_set_irq, ics, ics->nr_irqs);



    qemu_register_reset(ics_kvm_reset, dev);

}
