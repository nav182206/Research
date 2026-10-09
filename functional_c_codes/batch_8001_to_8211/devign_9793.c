/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9793
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a89d89d3e65800fa4a8e00de7af0ea8272bef779
 */

static int qemu_rbd_snap_remove(BlockDriverState *bs,

                                const char *snapshot_name)

{

    BDRVRBDState *s = bs->opaque;

    int r;



    r = rbd_snap_remove(s->image, snapshot_name);

    return r;

}
