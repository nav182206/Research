/* 
 * Benchmark Sample ID : devign_9463
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6886867e9880830d735d8ae6f6cc63ed9eb2be0c
 */

static void notdirty_mem_write(void *opaque, hwaddr ram_addr,

                               uint64_t val, unsigned size)

{

    if (!cpu_physical_memory_get_dirty_flag(ram_addr, DIRTY_MEMORY_CODE)) {

        tb_invalidate_phys_page_fast(ram_addr, size);

    }

    switch (size) {

    case 1:

        stb_p(qemu_get_ram_ptr(ram_addr), val);

        break;

    case 2:

        stw_p(qemu_get_ram_ptr(ram_addr), val);

        break;

    case 4:

        stl_p(qemu_get_ram_ptr(ram_addr), val);

        break;

    default:

        abort();

    }

    cpu_physical_memory_set_dirty_flag(ram_addr, DIRTY_MEMORY_MIGRATION);

    cpu_physical_memory_set_dirty_flag(ram_addr, DIRTY_MEMORY_VGA);

    /* we remove the notdirty callback only if the code has been

       flushed */

    if (!cpu_physical_memory_is_clean(ram_addr)) {

        CPUArchState *env = current_cpu->env_ptr;

        tlb_set_dirty(env, current_cpu->mem_io_vaddr);

    }

}
