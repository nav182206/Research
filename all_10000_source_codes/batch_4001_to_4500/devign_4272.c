/* 
 * Benchmark Sample ID : devign_4272
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=20873526a329e2145522c29775542dba2900ebe0
 */

static void suspend_request(BlockDriverState *bs, BlkdebugRule *rule)

{

    BDRVBlkdebugState *s = bs->opaque;

    BlkdebugSuspendedReq r;



    r = (BlkdebugSuspendedReq) {

        .co         = qemu_coroutine_self(),

        .tag        = g_strdup(rule->options.suspend.tag),

    };



    remove_rule(rule);

    QLIST_INSERT_HEAD(&s->suspended_reqs, &r, next);



    printf("blkdebug: Suspended request '%s'\n", r.tag);

    qemu_coroutine_yield();

    printf("blkdebug: Resuming request '%s'\n", r.tag);



    QLIST_REMOVE(&r, next);

    g_free(r.tag);

}
