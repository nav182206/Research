/* 
 * Benchmark Sample ID : devign_4457
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e88774971c33671477c9eb4a4cf1e65a047c9838
 */

void bdrv_commit_all(void)

{

    BlockDriverState *bs;



    QTAILQ_FOREACH(bs, &bdrv_states, list) {

        bdrv_commit(bs);

    }

}
