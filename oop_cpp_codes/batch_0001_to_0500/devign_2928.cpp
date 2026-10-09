/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2928
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5f531386210e844f0a6819404cde58da54c46a00
 */

static int mov_write_int8_metadata(AVFormatContext *s, AVIOContext *pb,

                                   const char *name, const char *tag,

                                   int len)

{

    AVDictionaryEntry *t = NULL;

    uint8_t num;



    if (!(t = av_dict_get(s->metadata, tag, NULL, 0)))

        return 0;

    num = t ? atoi(t->value) : 0;



    avio_wb32(pb, len+8);

    ffio_wfourcc(pb, name);

    if (len==4) avio_wb32(pb, num);

    else        avio_w8 (pb, num);

    return len+8;

}
