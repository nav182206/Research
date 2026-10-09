/* 
 * Benchmark Sample ID : devign_7151
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0491a2a07a44f6e5e6f34081835e402c07025fd2
 */

static inline void writer_print_string(WriterContext *wctx,

                                       const char *key, const char *val)

{

    wctx->writer->print_string(wctx, key, val);

    wctx->nb_item++;

}
