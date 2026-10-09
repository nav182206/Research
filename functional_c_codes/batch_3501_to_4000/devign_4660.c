/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4660
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a89d89d3e65800fa4a8e00de7af0ea8272bef779
 */

static int find_snapshot_by_id_or_name(BlockDriverState *bs, const char *name)

{

    BDRVQcowState *s = bs->opaque;

    int i, ret;



    ret = find_snapshot_by_id(bs, name);

    if (ret >= 0)

        return ret;

    for(i = 0; i < s->nb_snapshots; i++) {

        if (!strcmp(s->snapshots[i].name, name))

            return i;

    }

    return -1;

}
