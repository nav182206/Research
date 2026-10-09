/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_136
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f06b2031a31cdd3acf6f61a977e505b8c6b58f73
 */

void ga_channel_free(GAChannel *c)

{

    if (c->method == GA_CHANNEL_UNIX_LISTEN

        && c->listen_channel) {

        ga_channel_listen_close(c);

    }

    if (c->client_channel) {

        ga_channel_client_close(c);

    }

    g_free(c);

}
