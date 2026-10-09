/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2404
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static bool block_is_active(void *opaque)

{

    return block_mig_state.blk_enable == 1;

}
