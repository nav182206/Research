/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5792
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3a3b8502e6f0c8d30865c5f36d2c3ae4114000b5
 */

static int spapr_nvram_init(VIOsPAPRDevice *dev)

{

    sPAPRNVRAM *nvram = VIO_SPAPR_NVRAM(dev);



    if (nvram->drive) {

        nvram->size = bdrv_getlength(nvram->drive);

    } else {

        nvram->size = DEFAULT_NVRAM_SIZE;

        nvram->buf = g_malloc0(nvram->size);

    }



    if ((nvram->size < MIN_NVRAM_SIZE) || (nvram->size > MAX_NVRAM_SIZE)) {

        fprintf(stderr, "spapr-nvram must be between %d and %d bytes in size\n",

                MIN_NVRAM_SIZE, MAX_NVRAM_SIZE);

        return -1;

    }



    spapr_rtas_register("nvram-fetch", rtas_nvram_fetch);

    spapr_rtas_register("nvram-store", rtas_nvram_store);



    return 0;

}
