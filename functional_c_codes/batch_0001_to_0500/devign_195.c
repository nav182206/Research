/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_195
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=42bb9c9178ae7ac4c439172b1ae99cc29188a5c6
 */

xilinx_axidma_data_stream_push(StreamSlave *obj, unsigned char *buf, size_t len,

                               uint32_t *app)

{

    XilinxAXIDMAStreamSlave *ds = XILINX_AXI_DMA_DATA_STREAM(obj);

    struct Stream *s = &ds->dma->streams[1];

    size_t ret;



    if (!app) {

        hw_error("No stream app data!\n");

    }

    ret = stream_process_s2mem(s, buf, len, app);

    stream_update_irq(s);

    return ret;

}
