/* 
 * Benchmark Sample ID : devign_8340
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9c5ce8db2e5c2769ed2fd3d91928dd1853b5ce7c
 */

static void smbios_build_type_1_table(void)

{

    SMBIOS_BUILD_TABLE_PRE(1, 0x100, true); /* required */



    SMBIOS_TABLE_SET_STR(1, manufacturer_str, type1.manufacturer);

    SMBIOS_TABLE_SET_STR(1, product_name_str, type1.product);

    SMBIOS_TABLE_SET_STR(1, version_str, type1.version);

    SMBIOS_TABLE_SET_STR(1, serial_number_str, type1.serial);

    if (qemu_uuid_set) {

        smbios_encode_uuid(&t->uuid, qemu_uuid);

    } else {

        memset(&t->uuid, 0, 16);

    }

    t->wake_up_type = 0x06; /* power switch */

    SMBIOS_TABLE_SET_STR(1, sku_number_str, type1.sku);

    SMBIOS_TABLE_SET_STR(1, family_str, type1.family);



    SMBIOS_BUILD_TABLE_POST;

}
