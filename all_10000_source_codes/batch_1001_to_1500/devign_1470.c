/* 
 * Benchmark Sample ID : devign_1470
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d466d82faaf6e0e57a3a4be5e38e3902ef251ac3
 */

static av_cold int dvdsub_init(AVCodecContext *avctx)

{

    DVDSubContext *ctx = avctx->priv_data;

    char *data, *cur;



    if (!avctx->extradata || !avctx->extradata_size)

        return 0;



    data = av_malloc(avctx->extradata_size + 1);

    if (!data)

        return AVERROR(ENOMEM);

    memcpy(data, avctx->extradata, avctx->extradata_size);

    data[avctx->extradata_size] = '\0';

    cur = data;



    while (*cur) {

        if (strncmp("palette:", cur, 8) == 0) {

            int i;

            char *p = cur + 8;

            ctx->has_palette = 1;

            for (i = 0; i < 16; i++) {

                ctx->palette[i] = strtoul(p, &p, 16);

                while (*p == ',' || av_isspace(*p))

                    p++;

            }

        } else if (!strncmp("size:", cur, 5)) {

            int w, h;

            if (sscanf(cur + 5, "%dx%d", &w, &h) == 2) {

               int ret = ff_set_dimensions(avctx, w, h);

               if (ret < 0)

                   return ret;

            }

        }

        cur += strcspn(cur, "\n\r");

        cur += strspn(cur, "\n\r");

    }

    av_free(data);

    return 0;

}
