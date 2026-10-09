/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3819
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5fb6c7a8b26eab1a22207d24b4784bd2b39ab54b
 */

static void vnc_write_u32(VncState *vs, uint32_t value)

{

    uint8_t buf[4];



    buf[0] = (value >> 24) & 0xFF;

    buf[1] = (value >> 16) & 0xFF;

    buf[2] = (value >>  8) & 0xFF;

    buf[3] = value & 0xFF;



    vnc_write(vs, buf, 4);

}
