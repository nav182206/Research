/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4120
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=43771539d4666cba16298fc6b0ea63867425277c
 */

void qemu_ram_free_from_ptr(ram_addr_t addr)

{

    RAMBlock *block;



    /* This assumes the iothread lock is taken here too.  */

    qemu_mutex_lock_ramlist();

    QTAILQ_FOREACH(block, &ram_list.blocks, next) {

        if (addr == block->offset) {

            QTAILQ_REMOVE(&ram_list.blocks, block, next);

            ram_list.mru_block = NULL;

            ram_list.version++;

            g_free(block);

            break;

        }

    }

    qemu_mutex_unlock_ramlist();

}
