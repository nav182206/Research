/* 
 * Benchmark Sample ID : devign_5147
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=de1b1a7da9e6ddf42447271e519099a88b389e4a
 */

static int check(AVIOContext *pb, int64_t pos)

{

    int64_t ret = avio_seek(pb, pos, SEEK_SET);

    unsigned header;

    MPADecodeHeader sd;

    if (ret < 0)

        return ret;



    header = avio_rb32(pb);

    if (ff_mpa_check_header(header) < 0)

        return -1;

    if (avpriv_mpegaudio_decode_header(&sd, header) == 1)

        return -1;



    return sd.frame_size;

}
