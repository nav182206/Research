/* 
 * Benchmark Sample ID : devign_5966
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6c87e3d5967a1d731b5f591a8f0ee6c319c14ca8
 */

FWCfgState *fw_cfg_init_mem(hwaddr ctl_addr, hwaddr data_addr)

{

    DeviceState *dev;

    SysBusDevice *sbd;



    dev = qdev_create(NULL, TYPE_FW_CFG_MEM);

    qdev_prop_set_uint32(dev, "data_width",

                         fw_cfg_data_mem_ops.valid.max_access_size);



    fw_cfg_init1(dev);



    sbd = SYS_BUS_DEVICE(dev);

    sysbus_mmio_map(sbd, 0, ctl_addr);

    sysbus_mmio_map(sbd, 1, data_addr);



    return FW_CFG(dev);

}
