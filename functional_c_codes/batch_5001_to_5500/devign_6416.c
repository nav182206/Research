/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6416
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e5a869ed569a97fa676e9827952629086ec41f4e
 */

static int target_pread(int fd, abi_ulong ptr, abi_ulong len,

                        abi_ulong offset)

{

    void *buf;

    int ret;



    buf = lock_user(VERIFY_WRITE, ptr, len, 0);




    ret = pread(fd, buf, len, offset);




    unlock_user(buf, ptr, len);

    return ret;
