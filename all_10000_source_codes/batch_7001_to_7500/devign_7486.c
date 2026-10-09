/* 
 * Benchmark Sample ID : devign_7486
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b1fe60cd3525871a4c593ad8c2b39b89c19c00d0
 */

static void intel_hda_update_irq(IntelHDAState *d)

{

    int msi = d->msi && msi_enabled(&d->pci);

    int level;



    intel_hda_update_int_sts(d);

    if (d->int_sts & (1 << 31) && d->int_ctl & (1 << 31)) {

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
