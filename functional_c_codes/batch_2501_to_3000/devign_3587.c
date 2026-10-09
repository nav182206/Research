/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3587
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a89f364ae8740dfc31b321eed9ee454e996dc3c1
 */

DeviceState *nand_init(BlockBackend *blk, int manf_id, int chip_id)

{

    DeviceState *dev;



    if (nand_flash_ids[chip_id].size == 0) {

        hw_error("%s: Unsupported NAND chip ID.\n", __FUNCTION__);

    }

    dev = DEVICE(object_new(TYPE_NAND));

    qdev_prop_set_uint8(dev, "manufacturer_id", manf_id);

    qdev_prop_set_uint8(dev, "chip_id", chip_id);

    if (blk) {

        qdev_prop_set_drive(dev, "drive", blk, &error_fatal);

    }



    qdev_init_nofail(dev);

    return dev;

}
