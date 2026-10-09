/* 
 * Benchmark Sample ID : devign_9388
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=da98c8eb4c35225049cad8cf767647eb39788b5d
 */

i2c_bus *piix4_pm_init(PCIBus *bus, int devfn, uint32_t smb_io_base,

                       qemu_irq sci_irq, qemu_irq cmos_s3, qemu_irq smi_irq,

                       int kvm_enabled)

{

    PCIDevice *dev;

    PIIX4PMState *s;



    dev = pci_create(bus, devfn, "PIIX4_PM");

    qdev_prop_set_uint32(&dev->qdev, "smb_io_base", smb_io_base);



    s = DO_UPCAST(PIIX4PMState, dev, dev);

    s->irq = sci_irq;

    acpi_pm1_cnt_init(&s->ar, cmos_s3);

    s->smi_irq = smi_irq;

    s->kvm_enabled = kvm_enabled;



    qdev_init_nofail(&dev->qdev);



    return s->smb.smbus;

}
