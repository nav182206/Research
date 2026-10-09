/* 
 * Benchmark Sample ID : devign_6060
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ada8d2e4369ea49677d8672ac81bce73eefd5b54
 */

void vnc_jobs_consume_buffer(VncState *vs)
{
    bool flush;
    vnc_lock_output(vs);
    if (vs->jobs_buffer.offset) {
        if (vs->ioc != NULL && buffer_empty(&vs->output)) {
            if (vs->ioc_tag) {
                g_source_remove(vs->ioc_tag);
            vs->ioc_tag = qio_channel_add_watch(
                vs->ioc, G_IO_IN | G_IO_OUT, vnc_client_io, vs, NULL);
        buffer_move(&vs->output, &vs->jobs_buffer);
    flush = vs->ioc != NULL && vs->abort != true;
    vnc_unlock_output(vs);
    if (flush) {
      vnc_flush(vs);
