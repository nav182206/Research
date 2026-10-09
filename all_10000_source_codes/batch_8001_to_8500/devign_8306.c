/* 
 * Benchmark Sample ID : devign_8306
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=10c4c98ab7dc18169b37b76f6ea5e60ebe65222b
 */

void ssi_register_slave(SSISlaveInfo *info)

{

    assert(info->qdev.size >= sizeof(SSISlave));

    info->qdev.init = ssi_slave_init;

    info->qdev.bus_type = BUS_TYPE_SSI;

    qdev_register(&info->qdev);

}
