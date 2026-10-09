/* 
 * Benchmark Sample ID : devign_2462
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=70d54392f5015b9c6594fcae558f59f952501e3b
 */

void avcodec_set_dimensions(AVCodecContext *s, int width, int height){

    s->coded_width = width;

    s->coded_height= height;

    s->width  = width;

    s->height = height;

}
