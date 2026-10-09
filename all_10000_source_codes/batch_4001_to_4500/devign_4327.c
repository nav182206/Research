/* 
 * Benchmark Sample ID : devign_4327
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8f5d58ef2c92d7b82d9a6eeefd7c8854a183ba4a
 */

static void xlnx_dp_set_dpdma(Object *obj, const char *name, Object *val,

                              Error **errp)

{

    XlnxDPState *s = XLNX_DP(obj);

    if (s->console) {

        DisplaySurface *surface = qemu_console_surface(s->console);

        XlnxDPDMAState *dma = XLNX_DPDMA(val);

        xlnx_dpdma_set_host_data_location(dma, DP_GRAPHIC_DMA_CHANNEL,

                                          surface_data(surface));

    }

}
