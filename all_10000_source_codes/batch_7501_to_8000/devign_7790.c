/* 
 * Benchmark Sample ID : devign_7790
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=01e4537f66c6d054f8c7bdbdd5b3cfb4220d12fe
 */

static void flat_print_section_header(WriterContext *wctx)

{

    FlatContext *flat = wctx->priv;

    AVBPrint *buf = &flat->section_header[wctx->level];

    int i;



    /* build section header */

    av_bprint_clear(buf);

    for (i = 1; i <= wctx->level; i++) {

        if (flat->hierarchical ||

            !(wctx->section[i]->flags & (SECTION_FLAG_IS_ARRAY|SECTION_FLAG_IS_WRAPPER)))

            av_bprintf(buf, "%s%s", wctx->section[i]->name, flat->sep_str);

    }

}
