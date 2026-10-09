/* 
 * Benchmark Sample ID : devign_5580
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=08a2d4c4ffde60e48819449f461274c43ad6e2d3
 */

static void sdl_mouse_warp(int x, int y, int on)

{

    if (on) {

        if (!guest_cursor)

            sdl_show_cursor();

        if (gui_grab || kbd_mouse_is_absolute() || absolute_enabled) {

            SDL_SetCursor(guest_sprite);

            SDL_WarpMouse(x, y);

        }

    } else if (gui_grab)

        sdl_hide_cursor();

    guest_cursor = on;

    guest_x = x, guest_y = y;

}
