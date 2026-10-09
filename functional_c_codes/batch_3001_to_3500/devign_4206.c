/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4206
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e9cb190ad4cea8e6fd24afb973c5007b9a439bc9
 */

static void ivshmem_plain_init(Object *obj)

{

    IVShmemState *s = IVSHMEM_PLAIN(obj);



    object_property_add_link(obj, "memdev", TYPE_MEMORY_BACKEND,

                             (Object **)&s->hostmem,

                             ivshmem_check_memdev_is_busy,

                             OBJ_PROP_LINK_UNREF_ON_RELEASE,

                             &error_abort);

    s->not_legacy_32bit = 1;

}
