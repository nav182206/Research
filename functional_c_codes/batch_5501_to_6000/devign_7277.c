/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7277
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9be385980d37e8f4fd33f605f5fb1c3d144170a8
 */

int64_t qmp_guest_get_time(Error **errp)

{

   int ret;

   qemu_timeval tq;

   int64_t time_ns;



   ret = qemu_gettimeofday(&tq);

   if (ret < 0) {

       error_setg_errno(errp, errno, "Failed to get time");

       return -1;

   }



   time_ns = tq.tv_sec * 1000000000LL + tq.tv_usec * 1000;

   return time_ns;

}
