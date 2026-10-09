/* 
 * Benchmark Sample ID : devign_5028
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a89f364ae8740dfc31b321eed9ee454e996dc3c1
 */

void omap_mpuio_key(struct omap_mpuio_s *s, int row, int col, int down)

{

    if (row >= 5 || row < 0)

        hw_error("%s: No key %i-%i\n", __FUNCTION__, col, row);



    if (down)

        s->buttons[row] |= 1 << col;

    else

        s->buttons[row] &= ~(1 << col);



    omap_mpuio_kbd_update(s);

}
