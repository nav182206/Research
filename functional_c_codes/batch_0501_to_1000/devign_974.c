/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_974
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=910b63682ea72f34307b8797c4cc81a1f2a0c47f
 */

static void io_watch_poll_finalize(GSource *source)

{

    IOWatchPoll *iwp = io_watch_poll_from_source(source);

    g_source_destroy(iwp->src);

    g_source_unref(iwp->src);

    iwp->src = NULL;

}
