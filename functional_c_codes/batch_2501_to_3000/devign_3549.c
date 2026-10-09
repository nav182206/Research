/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3549
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=98f343395e937fa1db3a28dfb4f303f97cfddd6c
 */

static void emulated_push_type(EmulatedState *card, uint32_t type)

{

    EmulEvent *event = (EmulEvent *)g_malloc(sizeof(EmulEvent));



    assert(event);

    event->p.gen.type = type;

    emulated_push_event(card, event);

}
