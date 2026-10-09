/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9814
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5e5a94b60518002e8ecc7afa78a9e7565b23e38f
 */

bdrv_acct_start(BlockDriverState *bs, BlockAcctCookie *cookie, int64_t bytes,

        enum BlockAcctType type)

{

    assert(type < BDRV_MAX_IOTYPE);



    cookie->bytes = bytes;

    cookie->start_time_ns = get_clock();

    cookie->type = type;

}
