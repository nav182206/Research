/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1445
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=db39fcf1f690b02d612e2bfc00980700887abe03
 */

CharDriverState *qemu_chr_open_msmouse(void)

{

    CharDriverState *chr;



    chr = g_malloc0(sizeof(CharDriverState));

    chr->chr_write = msmouse_chr_write;

    chr->chr_close = msmouse_chr_close;

    chr->explicit_be_open = true;



    qemu_add_mouse_event_handler(msmouse_event, chr, 0, "QEMU Microsoft Mouse");



    return chr;

}
