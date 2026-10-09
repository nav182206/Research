/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6577
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fedf0d35aafc4f1f1e5f6dbc80cb23ae1ae49f0b
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



    curses_winch_init();



    dcl = (DisplayChangeListener *) g_malloc0(sizeof(DisplayChangeListener));

    dcl->ops = &dcl_ops;

    register_displaychangelistener(dcl);



    invalidate = 1;

}
