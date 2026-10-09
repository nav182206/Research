/* 
 * Benchmark Sample ID : devign_9462
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=41a2b9596c9ed2a827e16e749632752dd2686647
 */

static void ide_atapi_cmd_ok(IDEState *s)

{

    s->error = 0;

    s->status = READY_STAT;

    s->nsector = (s->nsector & ~7) | ATAPI_INT_REASON_IO | ATAPI_INT_REASON_CD;

    ide_set_irq(s);

}
