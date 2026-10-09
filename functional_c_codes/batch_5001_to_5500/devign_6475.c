/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6475
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e1c37d0e94048502f9874e6356ce7136d4b05bdb
 */

static MigrationState *migrate_init(Monitor *mon, int detach, int blk, int inc)

{

    MigrationState *s = migrate_get_current();

    int64_t bandwidth_limit = s->bandwidth_limit;



    memset(s, 0, sizeof(*s));

    s->bandwidth_limit = bandwidth_limit;

    s->blk = blk;

    s->shared = inc;



    /* s->mon is used for two things:

       - pass fd in fd migration

       - suspend/resume monitor for not detached migration

    */

    s->mon = mon;

    s->bandwidth_limit = bandwidth_limit;

    s->state = MIG_STATE_SETUP;



    if (!detach) {

        migrate_fd_monitor_suspend(s, mon);

    }



    return s;

}
