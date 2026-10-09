/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1083
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4956d0e5a6a555d31345c913485bcc4e0a53481e
 */

int64_t av_add_stable(AVRational ts_tb, int64_t ts, AVRational inc_tb, int64_t inc)

{

    inc_tb = av_mul_q(inc_tb, (AVRational) {inc, 1});



    if (av_cmp_q(inc_tb, ts_tb) < 0) {

        //increase step is too small for even 1 step to be representable

        return ts;

    } else {

        int64_t old = av_rescale_q(ts, ts_tb, inc_tb);

        int64_t old_ts = av_rescale_q(old, inc_tb, ts_tb);

        return av_rescale_q(old + 1, inc_tb, ts_tb) + (ts - old_ts);

    }

}
