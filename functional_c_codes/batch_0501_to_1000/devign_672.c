/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_672
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=687db4ed2ecd5fd74c94fbb420482823cca4ab7e
 */

static void blkverify_err(BlkverifyAIOCB *acb, const char *fmt, ...)

{

    va_list ap;



    va_start(ap, fmt);

    fprintf(stderr, "blkverify: %s sector_num=%ld nb_sectors=%d ",

            acb->is_write ? "write" : "read", acb->sector_num,

            acb->nb_sectors);

    vfprintf(stderr, fmt, ap);

    fprintf(stderr, "\n");

    va_end(ap);

    exit(1);

}
