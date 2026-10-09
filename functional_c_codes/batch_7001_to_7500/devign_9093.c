/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9093
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=12f86b5b3e1bdf75e0a467d771c16cc42f3a1f1a
 */

static void nvdimm_build_fit_buffer(NvdimmFitBuffer *fit_buf)

{

    qemu_mutex_lock(&fit_buf->lock);

    g_array_free(fit_buf->fit, true);

    fit_buf->fit = nvdimm_build_device_structure();

    fit_buf->dirty = true;

    qemu_mutex_unlock(&fit_buf->lock);

}
