/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9162
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8ba2aae32c40f544def6be7ae82be9bcb781e01d
 */

int uuid_is_null(const uuid_t uu)

{

    uuid_t null_uuid = { 0 };

    return memcmp(uu, null_uuid, sizeof(uuid_t)) == 0;

}
