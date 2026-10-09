/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3343
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=362e9299b34b3101aaa20f20363441c9f055fa5e
 */

static BlockStats *bdrv_query_stats(const BlockDriverState *bs,
                                    bool query_backing)
{
    BlockStats *s;
    s = g_malloc0(sizeof(*s));
    if (bdrv_get_device_name(bs)[0]) {
        s->has_device = true;
        s->device = g_strdup(bdrv_get_device_name(bs));
    }
    if (bdrv_get_node_name(bs)[0]) {
        s->has_node_name = true;
        s->node_name = g_strdup(bdrv_get_node_name(bs));
    }
    s->stats = g_malloc0(sizeof(*s->stats));
    if (bs->blk) {
        BlockAcctStats *stats = blk_get_stats(bs->blk);
        s->stats->rd_bytes = stats->nr_bytes[BLOCK_ACCT_READ];
        s->stats->wr_bytes = stats->nr_bytes[BLOCK_ACCT_WRITE];
        s->stats->rd_operations = stats->nr_ops[BLOCK_ACCT_READ];
        s->stats->wr_operations = stats->nr_ops[BLOCK_ACCT_WRITE];
        s->stats->failed_rd_operations = stats->failed_ops[BLOCK_ACCT_READ];
        s->stats->failed_wr_operations = stats->failed_ops[BLOCK_ACCT_WRITE];
        s->stats->failed_flush_operations = stats->failed_ops[BLOCK_ACCT_FLUSH];
        s->stats->invalid_rd_operations = stats->invalid_ops[BLOCK_ACCT_READ];
        s->stats->invalid_wr_operations = stats->invalid_ops[BLOCK_ACCT_WRITE];
        s->stats->invalid_flush_operations =
            stats->invalid_ops[BLOCK_ACCT_FLUSH];
        s->stats->rd_merged = stats->merged[BLOCK_ACCT_READ];
        s->stats->wr_merged = stats->merged[BLOCK_ACCT_WRITE];
        s->stats->flush_operations = stats->nr_ops[BLOCK_ACCT_FLUSH];
        s->stats->wr_total_time_ns = stats->total_time_ns[BLOCK_ACCT_WRITE];
        s->stats->rd_total_time_ns = stats->total_time_ns[BLOCK_ACCT_READ];
        s->stats->flush_total_time_ns = stats->total_time_ns[BLOCK_ACCT_FLUSH];
        s->stats->has_idle_time_ns = stats->last_access_time_ns > 0;
        if (s->stats->has_idle_time_ns) {
            s->stats->idle_time_ns = block_acct_idle_time_ns(stats);
        }
    }
    s->stats->wr_highest_offset = bs->wr_highest_offset;
    if (bs->file) {
        s->has_parent = true;
        s->parent = bdrv_query_stats(bs->file->bs, query_backing);
    }
    if (query_backing && bs->backing) {
        s->has_backing = true;
        s->backing = bdrv_query_stats(bs->backing->bs, query_backing);
    }
    return s;
}
