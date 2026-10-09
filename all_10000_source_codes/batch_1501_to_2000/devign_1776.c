/* 
 * Benchmark Sample ID : devign_1776
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e3807054e20fb3b94d18cb751c437ee2f43b6fac
 */

void qemu_ram_foreach_block(RAMBlockIterFunc func, void *opaque)

{

    RAMBlock *block;



    rcu_read_lock();

    QLIST_FOREACH_RCU(block, &ram_list.blocks, next) {

        func(block->host, block->offset, block->used_length, opaque);

    }

    rcu_read_unlock();

}
