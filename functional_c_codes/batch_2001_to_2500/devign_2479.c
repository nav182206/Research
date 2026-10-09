/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2479
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2c62f08ddbf3fa80dc7202eb9a2ea60ae44e2cc5
 */

int isa_vga_mm_init(hwaddr vram_base,

                    hwaddr ctrl_base, int it_shift,

                    MemoryRegion *address_space)

{

    ISAVGAMMState *s;



    s = g_malloc0(sizeof(*s));



    s->vga.vram_size_mb = VGA_RAM_SIZE >> 20;

    vga_common_init(&s->vga);

    vga_mm_init(s, vram_base, ctrl_base, it_shift, address_space);



    s->vga.con = graphic_console_init(s->vga.update, s->vga.invalidate,

                                      s->vga.screen_dump, s->vga.text_update,

                                      s);



    vga_init_vbe(&s->vga, address_space);

    return 0;

}
