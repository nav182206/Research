/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8214
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ae261c86aaed62e7acddafab8262a2bf286d40b7
 */

static int vmdk_write_cid(BlockDriverState *bs, uint32_t cid)

{

    char desc[DESC_SIZE], tmp_desc[DESC_SIZE];

    char *p_name, *tmp_str;

    BDRVVmdkState *s = bs->opaque;



    memset(desc, 0, sizeof(desc));

    if (bdrv_pread(bs->file, s->desc_offset, desc, DESC_SIZE) != DESC_SIZE) {

        return -EIO;

    }



    tmp_str = strstr(desc,"parentCID");

    pstrcpy(tmp_desc, sizeof(tmp_desc), tmp_str);

    if ((p_name = strstr(desc,"CID")) != NULL) {

        p_name += sizeof("CID");

        snprintf(p_name, sizeof(desc) - (p_name - desc), "%x\n", cid);

        pstrcat(desc, sizeof(desc), tmp_desc);

    }



    if (bdrv_pwrite_sync(bs->file, s->desc_offset, desc, DESC_SIZE) < 0) {

        return -EIO;

    }

    return 0;

}
