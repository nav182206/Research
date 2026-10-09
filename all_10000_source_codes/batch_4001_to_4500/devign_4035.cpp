/* 
 * Benchmark Sample ID : devign_4035
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e5dc1a6c6c4359cd783810f63eb68e9e09350708
 */

ReadLineState *readline_init(ReadLinePrintfFunc *printf_func,

                             ReadLineFlushFunc *flush_func,

                             void *opaque,

                             ReadLineCompletionFunc *completion_finder)

{

    ReadLineState *rs = g_malloc0(sizeof(*rs));



    rs->hist_entry = -1;

    rs->opaque = opaque;

    rs->printf_func = printf_func;

    rs->flush_func = flush_func;

    rs->completion_finder = completion_finder;



    return rs;

}
