/* 
 * Benchmark Sample ID : devign_3228
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fedf0d35aafc4f1f1e5f6dbc80cb23ae1ae49f0b
 */

static void text_console_resize(QemuConsole *s)

{

    TextCell *cells, *c, *c1;

    int w1, x, y, last_width;



    last_width = s->width;

    s->width = surface_width(s->surface) / FONT_WIDTH;

    s->height = surface_height(s->surface) / FONT_HEIGHT;



    w1 = last_width;

    if (s->width < w1)

        w1 = s->width;



    cells = g_malloc(s->width * s->total_height * sizeof(TextCell));

    for(y = 0; y < s->total_height; y++) {

        c = &cells[y * s->width];

        if (w1 > 0) {

            c1 = &s->cells[y * last_width];

            for(x = 0; x < w1; x++) {

                *c++ = *c1++;

            }

        }

        for(x = w1; x < s->width; x++) {

            c->ch = ' ';

            c->t_attrib = s->t_attrib_default;

            c++;

        }

    }

    g_free(s->cells);

    s->cells = cells;

}
