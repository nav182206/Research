/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3758
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d0cc2fbfa607678866475383c508be84818ceb64
 */

int event_notifier_set(EventNotifier *e)

{

    uint64_t value = 1;

    int r = write(e->fd, &value, sizeof(value));

    return r == sizeof(value);

}
