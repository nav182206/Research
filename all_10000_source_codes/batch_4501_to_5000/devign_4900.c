/* 
 * Benchmark Sample ID : devign_4900
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1de786777e0fb18ec1e44cea058c77e83980b6c4
 */

static int parse_ifo_palette(DVDSubContext *ctx, char *p)

{

    FILE *ifo;

    char ifostr[12];

    uint32_t sp_pgci, pgci, off_pgc, pgc;

    uint8_t r, g, b, yuv[65], *buf;

    int i, y, cb, cr, r_add, g_add, b_add;

    int ret = 0;

    const uint8_t *cm = ff_crop_tab + MAX_NEG_CROP;



    ctx->has_palette = 0;

    if ((ifo = fopen(p, "r")) == NULL) {

        av_log(ctx, AV_LOG_WARNING, "Unable to open IFO file \"%s\": %s\n", p, strerror(errno));

        return AVERROR_EOF;

    }

    if (fread(ifostr, 12, 1, ifo) != 1 || memcmp(ifostr, "DVDVIDEO-VTS", 12)) {

        av_log(ctx, AV_LOG_WARNING, "\"%s\" is not a proper IFO file\n", p);

        ret = AVERROR_INVALIDDATA;

        goto end;

    }

    fseek(ifo, 0xCC, SEEK_SET);

    if (fread(&sp_pgci, 4, 1, ifo) == 1) {

        pgci = av_be2ne32(sp_pgci) * 2048;

        fseek(ifo, pgci + 0x0C, SEEK_SET);

        if (fread(&off_pgc, 4, 1, ifo) == 1) {

            pgc = pgci + av_be2ne32(off_pgc);

            fseek(ifo, pgc + 0xA4, SEEK_SET);

            if (fread(yuv, 64, 1, ifo) == 1) {

                buf = yuv;

                for(i=0; i<16; i++) {

                    y  = *++buf;

                    cr = *++buf;

                    cb = *++buf;

                    YUV_TO_RGB1_CCIR(cb, cr);

                    YUV_TO_RGB2_CCIR(r, g, b, y);

                    ctx->palette[i] = (r << 16) + (g << 8) + b;

                    buf++;

                }

                ctx->has_palette = 1;

            }

        }

    }

    if (ctx->has_palette == 0) {

        av_log(ctx, AV_LOG_WARNING, "Failed to read palette from IFO file \"%s\"\n", p);

        ret = AVERROR_INVALIDDATA;

    }

end:

    fclose(ifo);

    return ret;

}
