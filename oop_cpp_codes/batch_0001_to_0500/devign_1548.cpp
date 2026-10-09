/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_1548
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static void sdhci_initfn(Object *obj)

{

    SDHCIState *s = SDHCI(obj);

    DriveInfo *di;



    di = drive_get_next(IF_SD);

    s->card = sd_init(di ? blk_bs(blk_by_legacy_dinfo(di)) : NULL, false);

    if (s->card == NULL) {

        exit(1);

    }

    s->eject_cb = qemu_allocate_irq(sdhci_insert_eject_cb, s, 0);

    s->ro_cb = qemu_allocate_irq(sdhci_card_readonly_cb, s, 0);

    sd_set_cb(s->card, s->ro_cb, s->eject_cb);



    s->insert_timer = timer_new_ns(QEMU_CLOCK_VIRTUAL, sdhci_raise_insertion_irq, s);

    s->transfer_timer = timer_new_ns(QEMU_CLOCK_VIRTUAL, sdhci_do_data_transfer, s);

}
