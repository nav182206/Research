/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2360
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=245f7b51c0ea04fb2224b1127430a096c91aee70
 */

static int send_sub_rect_solid(VncState *vs, int x, int y, int w, int h)

{

    vnc_framebuffer_update(vs, x, y, w, h, VNC_ENCODING_TIGHT);



    vnc_tight_start(vs);

    vnc_raw_send_framebuffer_update(vs, x, y, w, h);

    vnc_tight_stop(vs);



    return send_solid_rect(vs);

}
