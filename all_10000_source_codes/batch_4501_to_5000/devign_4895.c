/* 
 * Benchmark Sample ID : devign_4895
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

void sd_set_cb(SDState *sd, qemu_irq readonly, qemu_irq insert)

{

    sd->readonly_cb = readonly;

    sd->inserted_cb = insert;

    qemu_set_irq(readonly, sd->bdrv ? bdrv_is_read_only(sd->bdrv) : 0);

    qemu_set_irq(insert, sd->bdrv ? bdrv_is_inserted(sd->bdrv) : 0);

}
