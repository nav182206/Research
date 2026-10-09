/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9784
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e403e4bdbea08af0c4a068eb560b577d1b64cf7a
 */

static int64_t scene_sad8(FrameRateContext *s, uint8_t *p1, int p1_linesize, uint8_t* p2, int p2_linesize, int height)

{

    int64_t sad;

    int x, y;

    for (sad = y = 0; y < height; y += 8) {

        for (x = 0; x < p1_linesize; x += 8) {

            sad += s->sad(p1 + y * p1_linesize + x,

                          p1_linesize,

                          p2 + y * p2_linesize + x,

                          p2_linesize);

        }

    }

    emms_c();

    return sad;

}
