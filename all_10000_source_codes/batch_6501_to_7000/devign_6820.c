/* 
 * Benchmark Sample ID : devign_6820
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d8b2239bcd8872a5c5f7534d1658fc2365caab2d
 */

bool cpu_restore_state(CPUState *cpu, uintptr_t retaddr)
{
    TranslationBlock *tb;
    bool r = false;
    tb_lock();
    tb = tb_find_pc(retaddr);
    if (tb) {
        cpu_restore_state_from_tb(cpu, tb, retaddr);
        if (tb->cflags & CF_NOCACHE) {
            /* one-shot translation, invalidate it immediately */
            tb_phys_invalidate(tb, -1);
            tb_free(tb);
        r = true;
    tb_unlock();
