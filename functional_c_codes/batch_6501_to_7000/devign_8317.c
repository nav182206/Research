/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8317
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=482f7bf86b43af9f6903c52726fedf82b28bf953
 */

static void vga_update_display(void *opaque)

{

    VGACommonState *s = opaque;

    int full_update, graphic_mode;



    qemu_flush_coalesced_mmio_buffer();



    if (ds_get_bits_per_pixel(s->ds) == 0) {

        /* nothing to do */

    } else {

        full_update = 0;

        if (!(s->ar_index & 0x20)) {

            graphic_mode = GMODE_BLANK;

        } else {

            graphic_mode = s->gr[VGA_GFX_MISC] & VGA_GR06_GRAPHICS_MODE;

        }

        if (graphic_mode != s->graphic_mode) {

            s->graphic_mode = graphic_mode;

            s->cursor_blink_time = qemu_get_clock_ms(vm_clock);

            full_update = 1;

        }

        switch(graphic_mode) {

        case GMODE_TEXT:

            vga_draw_text(s, full_update);

            break;

        case GMODE_GRAPH:

            vga_draw_graphic(s, full_update);

            break;

        case GMODE_BLANK:

        default:

            vga_draw_blank(s, full_update);

            break;

        }

    }

}
