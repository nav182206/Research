/* 
 * Benchmark Sample ID : devign_9597
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static void remote_block_to_network(RDMARemoteBlock *rb)

{

    rb->remote_host_addr = htonll(rb->remote_host_addr);

    rb->offset = htonll(rb->offset);

    rb->length = htonll(rb->length);

    rb->remote_rkey = htonl(rb->remote_rkey);

}
