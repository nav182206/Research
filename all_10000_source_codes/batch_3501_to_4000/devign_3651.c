/* 
 * Benchmark Sample ID : devign_3651
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6e24ee0c1e4b6c0c9c748acab77ecd113c942a4d
 */

static void ps2_reset_keyboard(PS2KbdState *s)

{

    trace_ps2_reset_keyboard(s);

    s->scan_enabled = 1;

    s->scancode_set = 2;


    ps2_set_ledstate(s, 0);

}
