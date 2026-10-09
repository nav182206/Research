/* 
 * Benchmark Sample ID : devign_9145
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static void compress_to_network(RDMACompress *comp)

{

    comp->value = htonl(comp->value);

    comp->block_idx = htonl(comp->block_idx);

    comp->offset = htonll(comp->offset);

    comp->length = htonll(comp->length);

}
