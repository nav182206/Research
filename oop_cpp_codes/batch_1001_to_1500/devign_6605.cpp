/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_6605
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d4370741402a97b8b6d0c38fef18ab38bf25ab22
 */

static int gd_vc_chr_write(CharDriverState *chr, const uint8_t *buf, int len)

{

    VirtualConsole *vc = chr->opaque;



    return vc ? write(vc->fd, buf, len) : len;

}
