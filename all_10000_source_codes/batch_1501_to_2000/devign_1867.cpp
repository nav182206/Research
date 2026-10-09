/* 
 * Benchmark Sample ID : devign_1867
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2e6fc7eb1a4af1b127df5f07b8bb28af891946fa
 */

static int raw_probe_geometry(BlockDriverState *bs, HDGeometry *geo)

{

    BDRVRawState *s = bs->opaque;

    if (s->offset || s->has_size) {

        return -ENOTSUP;

    }

    return bdrv_probe_geometry(bs->file->bs, geo);

}
