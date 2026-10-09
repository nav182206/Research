/* 
 * Benchmark Sample ID : devign_9801
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9f61abc8111c7c43f49ca012e957a108b9cc7610
 */

static int init_file(AVFormatContext *s, OutputStream *os, int64_t start_ts)

{

    int ret, i;

    ret = avio_open2(&os->out, os->temp_filename, AVIO_FLAG_WRITE,

                     &s->interrupt_callback, NULL);

    if (ret < 0)

        return ret;

    avio_wb32(os->out, 0);

    avio_wl32(os->out, MKTAG('m','d','a','t'));

    for (i = 0; i < os->nb_extra_packets; i++) {

        AV_WB24(os->extra_packets[i] + 4, start_ts);

        os->extra_packets[i][7] = (start_ts >> 24) & 0x7f;

        avio_write(os->out, os->extra_packets[i], os->extra_packet_sizes[i]);

    }

    return 0;

}
