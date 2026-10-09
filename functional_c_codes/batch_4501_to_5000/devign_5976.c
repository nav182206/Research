/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5976
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=732b530c1bd064bdcc29975c0b78fc6de8c47e7f
 */

static void nvdimm_build_device_dsm(Aml *dev)

{

    Aml *method;



    method = aml_method("_DSM", 4, AML_NOTSERIALIZED);

    aml_append(method, aml_return(aml_call4(NVDIMM_COMMON_DSM, aml_arg(0),

                                  aml_arg(1), aml_arg(2), aml_arg(3))));

    aml_append(dev, method);

}
