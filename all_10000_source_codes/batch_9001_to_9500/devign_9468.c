/* 
 * Benchmark Sample ID : devign_9468
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5fb6c7a8b26eab1a22207d24b4784bd2b39ab54b
 */

static uint8_t read_u8(uint8_t *data, size_t offset)

{

    return data[offset];

}
