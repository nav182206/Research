/* 
 * Benchmark Sample ID : devign_7440
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8b47058c61af83c28231b860d46ee754ed7a9310
 */

static int ass_split(ASSSplitContext *ctx, const char *buf)

{

    char c, section[16];

    int i;



    if (ctx->current_section >= 0)

        buf = ass_split_section(ctx, buf);



    while (buf && *buf) {

        if (sscanf(buf, "[%15[0-9A-Za-z+ ]]%c", section, &c) == 2) {

            buf += strcspn(buf, "\n") + 1;

            for (i=0; i<FF_ARRAY_ELEMS(ass_sections); i++)

                if (!strcmp(section, ass_sections[i].section)) {

                    ctx->current_section = i;

                    buf = ass_split_section(ctx, buf);

                }

        } else

            buf += strcspn(buf, "\n") + 1;

    }

    return buf ? 0 : AVERROR_INVALIDDATA;

}
