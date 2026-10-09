/* 
 * Benchmark Sample ID : devign_5167
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a6109ff1b5d7184a9d490c4ff94f175940232ebd
 */

static void vmsvga_reset(struct vmsvga_state_s *s)

{

    s->index = 0;

    s->enable = 0;

    s->config = 0;

    s->width = -1;

    s->height = -1;

    s->svgaid = SVGA_ID;

    s->depth = 24;

    s->bypp = (s->depth + 7) >> 3;

    s->cursor.on = 0;

    s->redraw_fifo_first = 0;

    s->redraw_fifo_last = 0;

    switch (s->depth) {

    case 8:

        s->wred   = 0x00000007;

        s->wgreen = 0x00000038;

        s->wblue  = 0x000000c0;

        break;

    case 15:

        s->wred   = 0x0000001f;

        s->wgreen = 0x000003e0;

        s->wblue  = 0x00007c00;

        break;

    case 16:

        s->wred   = 0x0000001f;

        s->wgreen = 0x000007e0;

        s->wblue  = 0x0000f800;

        break;

    case 24:

        s->wred   = 0x00ff0000;

        s->wgreen = 0x0000ff00;

        s->wblue  = 0x000000ff;

        break;

    case 32:

        s->wred   = 0x00ff0000;

        s->wgreen = 0x0000ff00;

        s->wblue  = 0x000000ff;

        break;

    }

    s->syncing = 0;

}
