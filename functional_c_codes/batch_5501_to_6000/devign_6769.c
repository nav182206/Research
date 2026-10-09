/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6769
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0770a7a6466cc2dbf4ac91841173ad4488e1fbc7
 */

static void throttle_fix_bucket(LeakyBucket *bkt)

{

    double min;



    /* zero bucket level */

    bkt->level = bkt->burst_level = 0;



    /* The following is done to cope with the Linux CFQ block scheduler

     * which regroup reads and writes by block of 100ms in the guest.

     * When they are two process one making reads and one making writes cfq

     * make a pattern looking like the following:

     * WWWWWWWWWWWRRRRRRRRRRRRRRWWWWWWWWWWWWWwRRRRRRRRRRRRRRRRR

     * Having a max burst value of 100ms of the average will help smooth the

     * throttling

     */

    min = bkt->avg / 10;

    if (bkt->avg && !bkt->max) {

        bkt->max = min;

    }

}
