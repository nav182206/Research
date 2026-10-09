/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5633
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1b435b10324fe9937f254bb00718f78d5e50837a
 */

int qemu_bh_poll(void)

{

    QEMUBH *bh, **pbh;

    int ret;



    ret = 0;

    for(;;) {

        pbh = &first_bh;

        bh = *pbh;

        if (!bh)

            break;

        ret = 1;

        *pbh = bh->next;

        bh->scheduled = 0;

        bh->cb(bh->opaque);

    }

    return ret;

}
