/* 
 * Benchmark Sample ID : devign_8348
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static void network_to_result(RDMARegisterResult *result)

{

    result->rkey = ntohl(result->rkey);

    result->host_addr = ntohll(result->host_addr);

};
