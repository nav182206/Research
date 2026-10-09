/* 
 * Benchmark Sample ID : devign_9169
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static pflash_t *ve_pflash_cfi01_register(hwaddr base, const char *name,

                                          DriveInfo *di)

{

    DeviceState *dev = qdev_create(NULL, "cfi.pflash01");



    if (di && qdev_prop_set_drive(dev, "drive",

                                  blk_bs(blk_by_legacy_dinfo(di)))) {

        abort();

    }



    qdev_prop_set_uint32(dev, "num-blocks",

                         VEXPRESS_FLASH_SIZE / VEXPRESS_FLASH_SECT_SIZE);

    qdev_prop_set_uint64(dev, "sector-length", VEXPRESS_FLASH_SECT_SIZE);

    qdev_prop_set_uint8(dev, "width", 4);

    qdev_prop_set_uint8(dev, "device-width", 2);

    qdev_prop_set_uint8(dev, "big-endian", 0);

    qdev_prop_set_uint16(dev, "id0", 0x89);

    qdev_prop_set_uint16(dev, "id1", 0x18);

    qdev_prop_set_uint16(dev, "id2", 0x00);

    qdev_prop_set_uint16(dev, "id3", 0x00);

    qdev_prop_set_string(dev, "name", name);

    qdev_init_nofail(dev);



    sysbus_mmio_map(SYS_BUS_DEVICE(dev), 0, base);

    return OBJECT_CHECK(pflash_t, (dev), "cfi.pflash01");

}
