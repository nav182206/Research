/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5015
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5b08fc106d3146ddc1447d82d4770fc402fc363b
 */

void curses_display_init(DisplayState *ds, int full_screen)

{

#ifndef _WIN32

    if (!isatty(1)) {

        fprintf(stderr, "We need a terminal output\n");

        exit(1);

    }

#endif



    curses_setup();

    curses_keyboard_setup();

    atexit(curses_atexit);



#ifndef _WIN32

    signal(SIGINT, SIG_DFL);

    signal(SIGQUIT, SIG_DFL);

#if defined(SIGWINCH) && defined(KEY_RESIZE)

    /* some curses implementations provide a handler, but we

     * want to be sure this is handled regardless of the library */

    signal(SIGWINCH, curses_winch_handler);

#endif

#endif



    ds->data = (void *) screen;

    ds->linesize = 0;

    ds->depth = 0;

    ds->width = 640;

    ds->height = 400;

    ds->dpy_update = curses_update;

    ds->dpy_resize = curses_resize;

    ds->dpy_refresh = curses_refresh;

    ds->dpy_text_cursor = curses_cursor_position;



    invalidate = 1;



    /* Standard VGA initial text mode dimensions */

    curses_resize(ds, 80, 25);

}
