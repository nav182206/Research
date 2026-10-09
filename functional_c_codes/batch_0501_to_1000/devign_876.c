/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_876
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

DeviceState *nand_init(BlockDriverState *bdrv, int manf_id, int chip_id)

{

    DeviceState *dev;



    if (nand_flash_ids[chip_id].size == 0) {

        hw_error("%s: Unsupported NAND chip ID.\n", __FUNCTION__);

    }

    dev = DEVICE(object_new(TYPE_NAND));

    qdev_prop_set_uint8(dev, "manufacturer_id", manf_id);

    qdev_prop_set_uint8(dev, "chip_id", chip_id);

    if (bdrv) {

        qdev_prop_set_drive_nofail(dev, "drive", bdrv);

    }



    qdev_init_nofail(dev);

    return dev;

}
