/* 
 * Benchmark Sample ID : devign_3619
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fae2afb10e3fdceab612c62a2b1e8b944ff578d9
 */

static void qxl_log_cmd_draw_copy(PCIQXLDevice *qxl, QXLCopy *copy, int group_id)

{

    fprintf(stderr, " src %" PRIx64,

            copy->src_bitmap);

    qxl_log_image(qxl, copy->src_bitmap, group_id);

    fprintf(stderr, " area");

    qxl_log_rect(&copy->src_area);

    fprintf(stderr, " rop %d", copy->rop_descriptor);

}
