/* 
 * Benchmark Sample ID : devign_4577
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static void cmd_prevent_allow_medium_removal(IDEState *s, uint8_t* buf)

{

    s->tray_locked = buf[4] & 1;

    bdrv_lock_medium(s->bs, buf[4] & 1);

    ide_atapi_cmd_ok(s);

}
