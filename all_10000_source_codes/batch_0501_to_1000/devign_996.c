/* 
 * Benchmark Sample ID : devign_996
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=85f94f868fcd868f0f605e9d3c1ad6351c557190
 */

static void absolute_mouse_grab(void)

{

    int mouse_x, mouse_y;



    if (SDL_GetAppState() & SDL_APPINPUTFOCUS) {

        SDL_GetMouseState(&mouse_x, &mouse_y);

        if (mouse_x > 0 && mouse_x < real_screen->w - 1 &&

            mouse_y > 0 && mouse_y < real_screen->h - 1) {

            sdl_grab_start();

        }

    }

}
