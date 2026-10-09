/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7903
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8561c9244ddf1122dfe7ccac9b23f506062f1499
 */

static void reclaim_ramblock(RAMBlock *block)

{

    if (block->flags & RAM_PREALLOC) {

        ;

    } else if (xen_enabled()) {

        xen_invalidate_map_cache_entry(block->host);

#ifndef _WIN32

    } else if (block->fd >= 0) {

        munmap(block->host, block->max_length);

        close(block->fd);

#endif

    } else {

        qemu_anon_ram_free(block->host, block->max_length);

    }

    g_free(block);

}
