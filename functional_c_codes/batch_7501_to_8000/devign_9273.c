/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9273
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=eb2f9b024d68884a3b25e63e4dbf90b67f8da236
 */

static inline void vmsvga_check_size(struct vmsvga_state_s *s)

{

    DisplaySurface *surface = qemu_console_surface(s->vga.con);



    if (s->new_width != surface_width(surface) ||

        s->new_height != surface_height(surface)) {

        qemu_console_resize(s->vga.con, s->new_width, s->new_height);

        s->invalidated = 1;

    }

}
