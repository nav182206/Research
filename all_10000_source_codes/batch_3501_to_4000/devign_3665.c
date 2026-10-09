/* 
 * Benchmark Sample ID : devign_3665
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9ea63c05d90ba85d819f9b2472ce6dfba7a403b4
 */

static int do_subchannel_work(SubchDev *sch)

{

    if (sch->do_subchannel_work) {

        return sch->do_subchannel_work(sch);

    } else {

        return -EINVAL;

    }

}
