/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9284
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c508277335e3b6b20cf18e6ea3a35c1fa835c64a
 */

static void vmxnet3_update_rx_mode(VMXNET3State *s)

{

    s->rx_mode = VMXNET3_READ_DRV_SHARED32(s->drv_shmem,

                                           devRead.rxFilterConf.rxMode);

    VMW_CFPRN("RX mode: 0x%08X", s->rx_mode);

}
