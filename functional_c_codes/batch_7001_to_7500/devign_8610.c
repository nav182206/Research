/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8610
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bd269ebc82fbaa5fe7ce5bc7c1770ac8acecd884
 */

static void qio_channel_socket_dgram_worker_free(gpointer opaque)

{

    struct QIOChannelSocketDGramWorkerData *data = opaque;

    qapi_free_SocketAddressLegacy(data->localAddr);

    qapi_free_SocketAddressLegacy(data->remoteAddr);

    g_free(data);

}
