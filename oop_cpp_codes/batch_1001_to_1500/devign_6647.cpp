/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_6647
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cb88ebd7542458c22f3051646f268dcea6109abc
 */

static uint32_t nvdimm_get_max_xfer_label_size(void)

{

    uint32_t max_get_size, max_set_size, dsm_memory_size = 4096;



    /*

     * the max data ACPI can read one time which is transferred by

     * the response of 'Get Namespace Label Data' function.

     */

    max_get_size = dsm_memory_size - sizeof(NvdimmFuncGetLabelDataOut);



    /*

     * the max data ACPI can write one time which is transferred by

     * 'Set Namespace Label Data' function.

     */

    max_set_size = dsm_memory_size - offsetof(NvdimmDsmIn, arg3) -

                   sizeof(NvdimmFuncSetLabelDataIn);



    return MIN(max_get_size, max_set_size);

}
