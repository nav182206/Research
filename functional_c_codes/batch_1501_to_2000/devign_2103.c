/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2103
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4e2e4e6355959a1af011167b0db5ac7ffd3adf94
 */

static void set_gsi(KVMState *s, unsigned int gsi)

{

    assert(gsi < s->max_gsi);



    s->used_gsi_bitmap[gsi / 32] |= 1U << (gsi % 32);

}
