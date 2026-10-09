/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7668
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b10170aca0616df85482dcc7ddda03437bc07cca
 */

static int qed_write_header_sync(BDRVQEDState *s)

{

    QEDHeader le;

    int ret;



    qed_header_cpu_to_le(&s->header, &le);

    ret = bdrv_pwrite(s->bs->file, 0, &le, sizeof(le));

    if (ret != sizeof(le)) {

        return ret;

    }

    return 0;

}
