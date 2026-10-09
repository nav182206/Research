/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_37
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static void ide_set_signature(IDEState *s)

{

    s->select &= 0xf0; /* clear head */

    /* put signature */

    s->nsector = 1;

    s->sector = 1;

    if (s->drive_kind == IDE_CD) {

        s->lcyl = 0x14;

        s->hcyl = 0xeb;

    } else if (s->bs) {

        s->lcyl = 0;

        s->hcyl = 0;

    } else {

        s->lcyl = 0xff;

        s->hcyl = 0xff;

    }

}
