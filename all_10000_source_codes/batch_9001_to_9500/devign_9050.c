/* 
 * Benchmark Sample ID : devign_9050
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4efe27556dea874030f1cd53a6d70452ee064fba
 */

void isa_cirrus_vga_init(DisplayState *ds, uint8_t *vga_ram_base,

                         unsigned long vga_ram_offset, int vga_ram_size)

{

    CirrusVGAState *s;



    s = qemu_mallocz(sizeof(CirrusVGAState));



    vga_common_init((VGAState *)s,

                    ds, vga_ram_base, vga_ram_offset, vga_ram_size);

    cirrus_init_common(s, CIRRUS_ID_CLGD5430, 0);

    s->console = graphic_console_init(s->ds, s->update, s->invalidate,

                                      s->screen_dump, s->text_update, s);

    /* XXX ISA-LFB support */

}
