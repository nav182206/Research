/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6854
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1e85b5e077e7e6fb9901bfd1a7a4f2594ba5a9a5
 */

int ff_network_wait_fd_timeout(int fd, int write, int64_t timeout, AVIOInterruptCB *int_cb)

{

    int ret;

    int64_t wait_start = 0;



    while (1) {

        ret = ff_network_wait_fd(fd, write);

        if (ret != AVERROR(EAGAIN))

            return ret;

        if (ff_check_interrupt(int_cb))

            return AVERROR_EXIT;

        if (timeout > 0) {

            if (!wait_start)

                wait_start = av_gettime();

            else if (av_gettime() - wait_start > timeout)

                return AVERROR(ETIMEDOUT);

        }

    }

}
