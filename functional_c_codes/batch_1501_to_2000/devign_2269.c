/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2269
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3c90c65d7adab49a41952ee14e1d65f81355e408
 */

static void blkdebug_debug_event(BlockDriverState *bs, BlkDebugEvent event)

{

    BDRVBlkdebugState *s = bs->opaque;

    struct BlkdebugRule *rule;

    bool injected;



    assert((int)event >= 0 && event < BLKDBG_EVENT_MAX);



    injected = false;

    s->new_state = s->state;

    QLIST_FOREACH(rule, &s->rules[event], next) {

        injected = process_rule(bs, rule, injected);

    }

    s->state = s->new_state;

}
