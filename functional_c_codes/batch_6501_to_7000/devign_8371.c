/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8371
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=db56a7507ee7c1e095d2eef451d5a487f614edff
 */

static inline void drawbox(AVFilterBufferRef *picref, unsigned int x, unsigned int y,

                           unsigned int width, unsigned int height,

                           uint8_t *line[4], int pixel_step[4], uint8_t color[4],

                           int hsub, int vsub, int is_rgba_packed, uint8_t rgba_map[4])

{

    int i, j, alpha;



    if (color[3] != 0xFF) {

        if (is_rgba_packed) {

            uint8_t *p;

            for (j = 0; j < height; j++)

                for (i = 0; i < width; i++)

                    SET_PIXEL_RGB(picref, color, 255, i+x, y+j, pixel_step[0],

                                  rgba_map[0], rgba_map[1], rgba_map[2], rgba_map[3]);

        } else {

            unsigned int luma_pos, chroma_pos1, chroma_pos2;

            for (j = 0; j < height; j++)

                for (i = 0; i < width; i++)

                    SET_PIXEL_YUV(picref, color, 255, i+x, y+j, hsub, vsub);

        }

    } else {

        ff_draw_rectangle(picref->data, picref->linesize,

                          line, pixel_step, hsub, vsub,

                          x, y, width, height);

    }

}
