/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5682
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=21ef45d71221b4577330fe3aacfb06afad91ad46
 */

void vnc_display_add_client(DisplayState *ds, int csock, int skipauth)

{

    VncDisplay *vs = ds ? (VncDisplay *)ds->opaque : vnc_display;



    vnc_connect(vs, csock, skipauth, 0);

}
