/* 
 * Benchmark Sample ID : devign_3416
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c6bf8e0e0cf04b40a8a22426e00ebbd727331d8b
 */

static void migration_bitmap_sync(void)

{

    uint64_t num_dirty_pages_init = ram_list.dirty_pages;



    trace_migration_bitmap_sync_start();

    memory_global_sync_dirty_bitmap(get_system_memory());

    trace_migration_bitmap_sync_end(ram_list.dirty_pages

                                    - num_dirty_pages_init);

}
