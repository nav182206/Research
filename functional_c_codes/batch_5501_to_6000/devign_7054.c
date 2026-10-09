/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7054
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3a8c95f730732b9f1ffacdbfbf79a01b202a67af
 */

static void show_packets(AVFormatContext *fmt_ctx)

{

    AVPacket pkt;



    av_init_packet(&pkt);



    while (!av_read_frame(fmt_ctx, &pkt))

        show_packet(fmt_ctx, &pkt);

}
