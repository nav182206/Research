/* 
 * Benchmark Sample ID : devign_6786
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0e2fa9cab9c124788077de728f1e6744d1dd8bb2
 */

void helper_ldf_asi(target_ulong addr, int asi, int size, int rd)
{
    unsigned int i;
    target_ulong val;
    helper_check_align(addr, 3);
    addr = asi_address_mask(env, asi, addr);
    switch (asi) {
    case 0xf0: // Block load primary
    case 0xf1: // Block load secondary
    case 0xf8: // Block load primary LE
    case 0xf9: // Block load secondary LE
            *(uint32_t *)&env->fpr[rd++] = helper_ld_asi(addr, asi & 0x8f, 4,
    default:
        break;
    val = helper_ld_asi(addr, asi, size, 0);
    switch(size) {
    default:
    case 4:
        *((uint32_t *)&env->fpr[rd]) = val;
        break;
    case 8:
        *((int64_t *)&DT0) = val;
        break;
    case 16:
        // XXX
        break;
