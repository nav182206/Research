/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4396
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=90b2f3136778311fb5e097b8ee1f527518231c23
 */

static void read_info_chunk(AVFormatContext *s, int64_t size)

{

    AVIOContext *pb = s->pb;

    unsigned int i;

    unsigned int nb_entries = avio_rb32(pb);

    for (i = 0; i < nb_entries; i++) {

        char key[32];

        char value[1024];

        avio_get_str(pb, INT_MAX, key, sizeof(key));

        avio_get_str(pb, INT_MAX, value, sizeof(value));

        av_dict_set(&s->metadata, key, value, 0);

    }

}
