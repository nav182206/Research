/* 
 * Benchmark Sample ID : devign_4
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=57d77b3963ce1023eaf5ada8cba58b9379405cc8
 */

int av_opencl_buffer_write(cl_mem dst_cl_buf, uint8_t *src_buf, size_t buf_size)

{

    cl_int status;

    void *mapped = clEnqueueMapBuffer(gpu_env.command_queue, dst_cl_buf,

                                      CL_TRUE,CL_MAP_WRITE, 0, sizeof(uint8_t) * buf_size,

                                      0, NULL, NULL, &status);



    if (status != CL_SUCCESS) {

        av_log(&openclutils, AV_LOG_ERROR, "Could not map OpenCL buffer: %s\n", opencl_errstr(status));

        return AVERROR_EXTERNAL;

    }

    memcpy(mapped, src_buf, buf_size);



    status = clEnqueueUnmapMemObject(gpu_env.command_queue, dst_cl_buf, mapped, 0, NULL, NULL);

    if (status != CL_SUCCESS) {

        av_log(&openclutils, AV_LOG_ERROR, "Could not unmap OpenCL buffer: %s\n", opencl_errstr(status));

        return AVERROR_EXTERNAL;

    }

    return 0;

}
