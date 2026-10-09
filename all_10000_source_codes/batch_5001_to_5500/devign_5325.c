/* 
 * Benchmark Sample ID : devign_5325
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5797dcdc7ade30e8c4080d9282cd9e51b3566e14
 */

static void nvdimm_dsm_device(NvdimmDsmIn *in, hwaddr dsm_mem_addr)

{

    /* See the comments in nvdimm_dsm_root(). */

    if (!in->function) {

        nvdimm_dsm_function0(0 /* No function supported other than

                                  function 0 */, dsm_mem_addr);

        return;

    }



    /* No function except function 0 is supported yet. */

    nvdimm_dsm_no_payload(1 /* Not Supported */, dsm_mem_addr);

}
