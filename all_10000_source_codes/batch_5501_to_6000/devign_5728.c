/* 
 * Benchmark Sample ID : devign_5728
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5fb6c7a8b26eab1a22207d24b4784bd2b39ab54b
 */

static void vnc_write_u8(VncState *vs, uint8_t value)

{

    vnc_write(vs, (char *)&value, 1);

}
