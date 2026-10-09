/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5712
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=245f7b51c0ea04fb2224b1127430a096c91aee70
 */

static void extend_solid_area(VncState *vs, int x, int y, int w, int h,

                              uint32_t color, int *x_ptr, int *y_ptr,

                              int *w_ptr, int *h_ptr)

{

    int cx, cy;



    /* Try to extend the area upwards. */

    for ( cy = *y_ptr - 1;

          cy >= y && check_solid_tile(vs, *x_ptr, cy, *w_ptr, 1, &color, true);

          cy-- );

    *h_ptr += *y_ptr - (cy + 1);

    *y_ptr = cy + 1;



    /* ... downwards. */

    for ( cy = *y_ptr + *h_ptr;

          cy < y + h &&

              check_solid_tile(vs, *x_ptr, cy, *w_ptr, 1, &color, true);

          cy++ );

    *h_ptr += cy - (*y_ptr + *h_ptr);



    /* ... to the left. */

    for ( cx = *x_ptr - 1;

          cx >= x && check_solid_tile(vs, cx, *y_ptr, 1, *h_ptr, &color, true);

          cx-- );

    *w_ptr += *x_ptr - (cx + 1);

    *x_ptr = cx + 1;



    /* ... to the right. */

    for ( cx = *x_ptr + *w_ptr;

          cx < x + w &&

              check_solid_tile(vs, cx, *y_ptr, 1, *h_ptr, &color, true);

          cx++ );

    *w_ptr += cx - (*x_ptr + *w_ptr);

}
