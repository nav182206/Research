/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7844
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c508277335e3b6b20cf18e6ea3a35c1fa835c64a
 */

static void vmxnet3_update_pm_state(VMXNET3State *s)

{

    struct Vmxnet3_VariableLenConfDesc pm_descr;



    pm_descr.confLen =

        VMXNET3_READ_DRV_SHARED32(s->drv_shmem, devRead.pmConfDesc.confLen);

    pm_descr.confVer =

        VMXNET3_READ_DRV_SHARED32(s->drv_shmem, devRead.pmConfDesc.confVer);

    pm_descr.confPA =

        VMXNET3_READ_DRV_SHARED64(s->drv_shmem, devRead.pmConfDesc.confPA);



    vmxnet3_dump_conf_descr("PM State", &pm_descr);

}
