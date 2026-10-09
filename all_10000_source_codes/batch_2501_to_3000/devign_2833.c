/* 
 * Benchmark Sample ID : devign_2833
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=50ab0e0908d592b8bda56c2d7495e1190d734b0b
 */

static void replication_close(BlockDriverState *bs)

{

    BDRVReplicationState *s = bs->opaque;



    if (s->replication_state == BLOCK_REPLICATION_RUNNING) {

        replication_stop(s->rs, false, NULL);







    if (s->mode == REPLICATION_MODE_SECONDARY) {

        g_free(s->top_id);




    replication_remove(s->rs);
