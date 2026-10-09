/* 
 * Benchmark Sample ID : devign_5478
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=21ef45d71221b4577330fe3aacfb06afad91ad46
 */

char *vnc_display_local_addr(DisplayState *ds)

{

    VncDisplay *vs = ds ? (VncDisplay *)ds->opaque : vnc_display;

    

    return vnc_socket_local_addr("%s:%s", vs->lsock);

}
