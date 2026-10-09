/* 
 * Benchmark Sample ID : devign_6315
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a89f364ae8740dfc31b321eed9ee454e996dc3c1
 */

static void intel_hda_update_irq(IntelHDAState *d)

{

    bool msi = msi_enabled(&d->pci);

    int level;



    intel_hda_update_int_sts(d);

    if (d->int_sts & (1U << 31) && d->int_ctl & (1U << 31)) {

        level = 1;

    } else {

        level = 0;

    }

    dprint(d, 2, "%s: level %d [%s]\n", __FUNCTION__,

           level, msi ? "msi" : "intx");

    if (msi) {

        if (level) {

            msi_notify(&d->pci, 0);

        }

    } else {

        pci_set_irq(&d->pci, level);

    }

}
