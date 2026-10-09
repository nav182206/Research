/* 
 * Benchmark Sample ID : devign_1047
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d0d7708ba29cbcc343364a46bff981e0ff88366f
 */

CharDriverState *qemu_chr_open_eventfd(int eventfd)

{

    CharDriverState *chr = qemu_chr_open_fd(eventfd, eventfd);



    if (chr) {

        chr->avail_connections = 1;

    }



    return chr;

}
