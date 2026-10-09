/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5188
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=bf87908cd8da31e8f8fe75c06577170928ea70a8
 */

static void rm_read_metadata(AVFormatContext *s, int wide)

{

    char buf[1024];

    int i;

    for (i=0; i<FF_ARRAY_ELEMS(ff_rm_metadata); i++) {

        int len = wide ? avio_rb16(s->pb) : avio_r8(s->pb);

        get_strl(s->pb, buf, sizeof(buf), len);

        av_dict_set(&s->metadata, ff_rm_metadata[i], buf, 0);

    }

}
