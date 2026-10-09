/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9458
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d0cc2fbfa607678866475383c508be84818ceb64
 */

int event_notifier_init(EventNotifier *e, int active)

{

#ifdef CONFIG_EVENTFD

    int fd = eventfd(!!active, EFD_NONBLOCK | EFD_CLOEXEC);

    if (fd < 0)

        return -errno;

    e->fd = fd;

    return 0;

#else

    return -ENOSYS;

#endif

}
