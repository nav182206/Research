/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8020
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0ead93120eb7bd770b32adc00b5ec1ee721626dc
 */

static bool is_sector_request_lun_aligned(int64_t sector_num, int nb_sectors,

                                          IscsiLun *iscsilun)

{

    assert(nb_sectors < BDRV_REQUEST_MAX_SECTORS);

    return is_byte_request_lun_aligned(sector_num << BDRV_SECTOR_BITS,

                                       nb_sectors << BDRV_SECTOR_BITS,

                                       iscsilun);

}
