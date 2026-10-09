/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2027
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=22b985d59c007c4422aefe3ef3fca0aa0daafa9f
 */

static void denoise_depth(HQDN3DContext *s,

                          uint8_t *src, uint8_t *dst,

                          uint16_t *line_ant, uint16_t **frame_ant_ptr,

                          int w, int h, int sstride, int dstride,

                          int16_t *spatial, int16_t *temporal, int depth)

{

    // FIXME: For 16bit depth, frame_ant could be a pointer to the previous

    // filtered frame rather than a separate buffer.

    long x, y;

    uint16_t *frame_ant = *frame_ant_ptr;

    if (!frame_ant) {

        uint8_t *frame_src = src;

        *frame_ant_ptr = frame_ant = av_malloc(w*h*sizeof(uint16_t));

        for (y = 0; y < h; y++, src += sstride, frame_ant += w)

            for (x = 0; x < w; x++)

                frame_ant[x] = LOAD(x);

        src = frame_src;

        frame_ant = *frame_ant_ptr;

    }



    if (spatial[0])

        denoise_spatial(s, src, dst, line_ant, frame_ant,

                        w, h, sstride, dstride, spatial, temporal, depth);

    else

        denoise_temporal(src, dst, frame_ant,

                         w, h, sstride, dstride, temporal, depth);

    emms_c();

}
