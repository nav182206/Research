/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5847
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static uint64_t htonll(uint64_t v)

{

    union { uint32_t lv[2]; uint64_t llv; } u;

    u.lv[0] = htonl(v >> 32);

    u.lv[1] = htonl(v & 0xFFFFFFFFULL);

    return u.llv;

}
