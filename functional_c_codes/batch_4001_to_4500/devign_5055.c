/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5055
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=207f328afc2137d422f59293ba37b8be5d3e1617
 */

void vnc_sent_lossy_rect(VncState *vs, int x, int y, int w, int h)

{

    int i, j;



    w = (x + w) / VNC_STAT_RECT;

    h = (y + h) / VNC_STAT_RECT;

    x /= VNC_STAT_RECT;

    y /= VNC_STAT_RECT;



    for (j = y; j <= y + h; j++) {

        for (i = x; i <= x + w; i++) {

            vs->lossy_rect[j][i] = 1;

        }

    }

}
