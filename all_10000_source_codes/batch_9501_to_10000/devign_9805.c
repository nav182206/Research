/* 
 * Benchmark Sample ID : devign_9805
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static gboolean qio_channel_yield_enter(QIOChannel *ioc,

                                        GIOCondition condition,

                                        gpointer opaque)

{

    QIOChannelYieldData *data = opaque;

    qemu_coroutine_enter(data->co, NULL);

    return FALSE;

}
