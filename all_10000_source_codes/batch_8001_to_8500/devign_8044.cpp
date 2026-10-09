/* 
 * Benchmark Sample ID : devign_8044
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e23e400ec62a03dea58ddb38479b4f1ef86f556d
 */

static int write_l1_entry(BlockDriverState *bs, int l1_index)

{

    BDRVQcowState *s = bs->opaque;

    uint64_t buf[L1_ENTRIES_PER_SECTOR];

    int l1_start_index;

    int i, ret;



    l1_start_index = l1_index & ~(L1_ENTRIES_PER_SECTOR - 1);

    for (i = 0; i < L1_ENTRIES_PER_SECTOR; i++) {

        buf[i] = cpu_to_be64(s->l1_table[l1_start_index + i]);

    }



    ret = qcow2_pre_write_overlap_check(bs,

            QCOW2_OL_DEFAULT & ~QCOW2_OL_ACTIVE_L1,

            s->l1_table_offset + 8 * l1_start_index, sizeof(buf));

    if (ret < 0) {

        return ret;

    }



    BLKDBG_EVENT(bs->file, BLKDBG_L1_UPDATE);

    ret = bdrv_pwrite_sync(bs->file, s->l1_table_offset + 8 * l1_start_index,

        buf, sizeof(buf));

    if (ret < 0) {

        return ret;

    }



    return 0;

}
