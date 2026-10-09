/* 
 * Benchmark Sample ID : devign_3847
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5e8e3c4c75c199aa1017db816fca02be2a9f8798
 */

static void virgl_cmd_resource_unref(VirtIOGPU *g,

                                     struct virtio_gpu_ctrl_command *cmd)

{

    struct virtio_gpu_resource_unref unref;





    VIRTIO_GPU_FILL_CMD(unref);

    trace_virtio_gpu_cmd_res_unref(unref.resource_id);









    virgl_renderer_resource_unref(unref.resource_id);
