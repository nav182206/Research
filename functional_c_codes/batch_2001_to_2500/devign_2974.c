/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2974
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cbcfa0418f0c196afa765f5c9837b9344d1adcf3
 */

int qemu_get_thread_id(void)

{

#if defined (__linux__)

    return syscall(SYS_gettid);

#else

    return getpid();

#endif

}
