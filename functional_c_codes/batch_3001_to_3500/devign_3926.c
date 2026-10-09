/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3926
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f06b2031a31cdd3acf6f61a977e505b8c6b58f73
 */

static void ga_channel_listen_close(GAChannel *c)

{

    g_assert(c->method == GA_CHANNEL_UNIX_LISTEN);

    g_assert(c->listen_channel);

    g_io_channel_shutdown(c->listen_channel, true, NULL);

    g_io_channel_unref(c->listen_channel);

    c->listen_channel = NULL;

}
