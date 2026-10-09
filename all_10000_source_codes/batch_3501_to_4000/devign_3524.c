/* 
 * Benchmark Sample ID : devign_3524
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a426e122173f36f05ea2cb72dcff77b7408546ce
 */

int kvm_vm_ioctl(KVMState *s, int type, ...)

{

    int ret;

    void *arg;

    va_list ap;



    va_start(ap, type);

    arg = va_arg(ap, void *);

    va_end(ap);



    ret = ioctl(s->vmfd, type, arg);

    if (ret == -1)

        ret = -errno;



    return ret;

}
