/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6879
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5a33db78b0f3ee808a3d8dd5c427edfbe80bdc73
 */

static void nvdimm_dsm_reserved_root(AcpiNVDIMMState *state, NvdimmDsmIn *in,

                                     hwaddr dsm_mem_addr)

{

    switch (in->function) {

    case 0x0:

        nvdimm_dsm_function0(0x1 | 1 << 1 /* Read FIT */, dsm_mem_addr);

        return;

    case 0x1 /* Read FIT */:

        nvdimm_dsm_func_read_fit(state, in, dsm_mem_addr);

        return;

    }



    nvdimm_dsm_no_payload(NVDIMM_DSM_RET_STATUS_UNSUPPORT, dsm_mem_addr);

}
