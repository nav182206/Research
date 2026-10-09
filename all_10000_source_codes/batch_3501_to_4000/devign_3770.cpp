/* 
 * Benchmark Sample ID : devign_3770
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9118e7f08f39001c92d595090b41305ef45c200a
 */

static void cdrom_change_cb(void *opaque)

{

    IDEState *s = opaque;

    uint64_t nb_sectors;



    /* XXX: send interrupt too */

    bdrv_get_geometry(s->bs, &nb_sectors);

    s->nb_sectors = nb_sectors;

}
