/* 
 * Benchmark Sample ID : devign_2248
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

void imx_timerp_create(const target_phys_addr_t addr,

                              qemu_irq irq,

                              DeviceState *ccm)

{

    IMXTimerPState *pp;

    DeviceState *dev;



    dev = sysbus_create_simple("imx_timerp", addr, irq);

    pp = container_of(dev, IMXTimerPState, busdev.qdev);

    pp->ccm = ccm;

}
