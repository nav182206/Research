/* 
 * Benchmark Sample ID : devign_9783
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=38a4be3fa7a7bb83f0a553577427e916a7bda390
 */

static int has_decode_delay_been_guessed(AVStream *st)

{

    return st->codec->codec_id != CODEC_ID_H264 ||

        st->codec_info_nb_frames >= 6 + st->codec->has_b_frames;

}
