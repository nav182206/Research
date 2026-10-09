/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_74
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=967d2ae616a1fc6ffc2c00810e09c232dfdb7911
 */

void ff_xvmc_init_block(MpegEncContext *s)

{

    struct xvmc_render_state *render = (struct xvmc_render_state*)s->current_picture.data[2];

    assert(render);

    if (!render || render->magic != AV_XVMC_RENDER_MAGIC) {

        assert(0);

        return; // make sure that this is a render packet

    }

    s->block = (DCTELEM *)(render->data_blocks + render->next_free_data_block_num * 64);

}
