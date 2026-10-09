/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9947
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=92e483f8ed70d88d4f64337f65bae212502735d4
 */

static int compare_ocl_device_desc(const void *a, const void *b)

{

    return ((const OpenCLDeviceBenchmark*)a)->runtime - ((const OpenCLDeviceBenchmark*)b)->runtime;

}
