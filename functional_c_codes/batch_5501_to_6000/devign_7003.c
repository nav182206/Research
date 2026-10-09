/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7003
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3eedd29bd7df6f21a79e1a67a6d905049996d2ec
 */

static void set_palette(AVFrame * frame, const uint8_t * palette_buffer)

{

    uint32_t * palette = (uint32_t *)frame->data[1];

    int a;

    for(a = 0; a < 256; a++){

        palette[a] = AV_RB24(&palette_buffer[a * 3]) * 4;

    }

    frame->palette_has_changed = 1;

}
