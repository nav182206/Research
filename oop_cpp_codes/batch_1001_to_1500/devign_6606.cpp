/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_6606
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8e094dd6674e3fd503e1fc2f68883fd3f73a5bd1
 */

int av_parse_color(uint8_t *rgba_color, const char *color_string, void *log_ctx)

{

    if (!strcasecmp(color_string, "random") || !strcasecmp(color_string, "bikeshed")) {

        int rgba = av_get_random_seed();

        rgba_color[0] = rgba >> 24;

        rgba_color[1] = rgba >> 16;

        rgba_color[2] = rgba >> 8;

        rgba_color[3] = rgba;

    } else

    if (!strncmp(color_string, "0x", 2)) {

        char *tail;

        int len = strlen(color_string);

        unsigned int rgba = strtoul(color_string, &tail, 16);



        if (*tail || (len != 8 && len != 10)) {

            av_log(log_ctx, AV_LOG_ERROR, "Invalid 0xRRGGBB[AA] color string: '%s'\n", color_string);

            return AVERROR(EINVAL);

        }

        if (len == 10) {

            rgba_color[3] = rgba;

            rgba >>= 8;

        }

        rgba_color[0] = rgba >> 16;

        rgba_color[1] = rgba >> 8;

        rgba_color[2] = rgba;

    } else {

        const ColorEntry *entry = bsearch(color_string,

                                          color_table,

                                          FF_ARRAY_ELEMS(color_table),

                                          sizeof(ColorEntry),

                                          color_table_compare);

        if (!entry) {

            av_log(log_ctx, AV_LOG_ERROR, "Cannot find color '%s'\n", color_string);

            return AVERROR(EINVAL);

        }

        memcpy(rgba_color, entry->rgba_color, 4);

    }



    return 0;

}
