/* 
 * Benchmark Sample ID : devign_8535
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=05340be97bc395ca0b544c6d856469894ecbf5eb
 */

static int img_read_seek(AVFormatContext *s, int stream_index, int64_t timestamp, int flags)

{

    VideoDemuxData *s1 = s->priv_data;



    if (timestamp < 0 || timestamp > s1->img_last - s1->img_first)

        return -1;

    s1->img_number = timestamp + s1->img_first;

    return 0;

}
