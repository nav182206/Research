/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7583
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9d8256ebc0ef88fb1f35d0405893962d20cc10ad
 */

void dpy_gl_scanout(QemuConsole *con,

                    uint32_t backing_id, bool backing_y_0_top,


                    uint32_t x, uint32_t y, uint32_t width, uint32_t height)

{

    assert(con->gl);

    con->gl->ops->dpy_gl_scanout(con->gl, backing_id,

                                 backing_y_0_top,


                                 x, y, width, height);

}
