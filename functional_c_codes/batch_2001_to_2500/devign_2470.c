/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2470
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=917507b01efea8017bfcb4188ac696612e363e72
 */

static abi_long do_connect(int sockfd, abi_ulong target_addr,

                           socklen_t addrlen)

{

    void *addr;



    if (addrlen < 0)

        return -TARGET_EINVAL;



    addr = alloca(addrlen);



    target_to_host_sockaddr(addr, target_addr, addrlen);

    return get_errno(connect(sockfd, addr, addrlen));

}
