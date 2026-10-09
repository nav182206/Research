/* 
 * Benchmark Sample ID : devign_7962
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=29b5f3115d9f217758bebd1d00e541aa3e739d2a
 */

int ff_framesync_dualinput_get_writable(FFFrameSync *fs, AVFrame **f0, AVFrame **f1)

{

    int ret;



    ret = ff_framesync_dualinput_get(fs, f0, f1);

    if (ret < 0)

        return ret;

    ret = ff_inlink_make_frame_writable(fs->parent->inputs[0], f0);

    if (ret < 0) {

        av_frame_free(f0);

        av_frame_free(f1);

        return ret;

    }

    return 0;

}
