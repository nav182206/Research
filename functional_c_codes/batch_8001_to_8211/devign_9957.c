/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9957
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=078a458e077d6b0db262c4b05fee51d01de2d1d2
 */

static int rewrite_footer(BlockDriverState* bs)

{

    int ret;

    BDRVVPCState *s = bs->opaque;

    int64_t offset = s->free_data_block_offset;



    ret = bdrv_pwrite(bs->file, offset, s->footer_buf, HEADER_SIZE);

    if (ret < 0)

        return ret;



    return 0;

}
