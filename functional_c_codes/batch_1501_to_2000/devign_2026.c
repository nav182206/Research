/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2026
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dc6b99d6b20e832a7d353474c2d093f8b2fb17d2
 */

static int mov_write_wfex_tag(AVIOContext *pb, MOVTrack *track)

{

    int64_t pos = avio_tell(pb);

    avio_wb32(pb, 0);

    ffio_wfourcc(pb, "wfex");

    ff_put_wav_header(pb, track->enc, FF_PUT_WAV_HEADER_FORCE_WAVEFORMATEX);

    return update_size(pb, pos);

}
