/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8686
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0e2fa9cab9c124788077de728f1e6744d1dd8bb2
 */

void helper_stf_asi(target_ulong addr, int asi, int size, int rd)
{
    unsigned int i;
    target_ulong val = 0;
    helper_check_align(addr, 3);
    addr = asi_address_mask(env, asi, addr);
    switch (asi) {
    case 0xe0: // UA2007 Block commit store primary (cache flush)
    case 0xe1: // UA2007 Block commit store secondary (cache flush)
    case 0xf0: // Block store primary
    case 0xf1: // Block store secondary
    case 0xf8: // Block store primary LE
    case 0xf9: // Block store secondary LE
            helper_st_asi(addr, val, asi & 0x8f, 4);
    default:
        break;
    switch(size) {
    default:
    case 4:
        val = *((uint32_t *)&env->fpr[rd]);
        break;
    case 8:
        val = *((int64_t *)&DT0);
        break;
    case 16:
        // XXX
        break;
    helper_st_asi(addr, val, asi, size);
