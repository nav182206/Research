/* 
 * Benchmark Sample ID : devign_4579
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=38e047b50d2bfd1df99fbbca884c9f1db0785ff4
 */

void cpu_exec_init_all(void)

{

#if !defined(CONFIG_USER_ONLY)

    qemu_mutex_init(&ram_list.mutex);

    memory_map_init();

    io_mem_init();

#endif

}
