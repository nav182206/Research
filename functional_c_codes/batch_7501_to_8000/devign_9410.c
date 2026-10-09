/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9410
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2d1cd6c7a91a4beb99a0c3a21be529222a708545
 */

static void update_cursor_data_virgl(VirtIOGPU *g,

                                     struct virtio_gpu_scanout *s,

                                     uint32_t resource_id)

{

    uint32_t width, height;

    uint32_t pixels, *data;



    data = virgl_renderer_get_cursor_data(resource_id, &width, &height);

    if (!data) {

        return;

    }



    if (width != s->current_cursor->width ||

        height != s->current_cursor->height) {


        return;

    }



    pixels = s->current_cursor->width * s->current_cursor->height;

    memcpy(s->current_cursor->data, data, pixels * sizeof(uint32_t));


}
