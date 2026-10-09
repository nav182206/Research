/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_349
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9dfd24ed848228643293e37c36848b5ac520ab98
 */

static void tpm_tis_initfn(Object *obj)

{

    ISADevice *dev = ISA_DEVICE(obj);

    TPMState *s = TPM(obj);



    memory_region_init_io(&s->mmio, OBJECT(s), &tpm_tis_memory_ops,

                          s, "tpm-tis-mmio",

                          TPM_TIS_NUM_LOCALITIES << TPM_TIS_LOCALITY_SHIFT);

    memory_region_add_subregion(isa_address_space(dev), TPM_TIS_ADDR_BASE,

                                &s->mmio);

}
