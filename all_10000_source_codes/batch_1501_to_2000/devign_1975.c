/* 
 * Benchmark Sample ID : devign_1975
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fd28aa132362320f9f3a30b23f634bb14dee528e
 */

void qemu_ram_remap(ram_addr_t addr, ram_addr_t length)

{

    RAMBlock *block;

    ram_addr_t offset;

    int flags;

    void *area, *vaddr;



    QLIST_FOREACH(block, &ram_list.blocks, next) {

        offset = addr - block->offset;

        if (offset < block->length) {

            vaddr = block->host + offset;

            if (block->flags & RAM_PREALLOC_MASK) {

                ;

            } else {

                flags = MAP_FIXED;

                munmap(vaddr, length);

                if (mem_path) {

#if defined(__linux__) && !defined(TARGET_S390X)

                    if (block->fd) {

#ifdef MAP_POPULATE

                        flags |= mem_prealloc ? MAP_POPULATE | MAP_SHARED :

                            MAP_PRIVATE;


                        flags |= MAP_PRIVATE;

#endif

                        area = mmap(vaddr, length, PROT_READ | PROT_WRITE,

                                    flags, block->fd, offset);

                    } else {

                        flags |= MAP_PRIVATE | MAP_ANONYMOUS;

                        area = mmap(vaddr, length, PROT_READ | PROT_WRITE,

                                    flags, -1, 0);

                    }



#endif

                } else {

#if defined(TARGET_S390X) && defined(CONFIG_KVM)

                    flags |= MAP_SHARED | MAP_ANONYMOUS;

                    area = mmap(vaddr, length, PROT_EXEC|PROT_READ|PROT_WRITE,

                                flags, -1, 0);


                    flags |= MAP_PRIVATE | MAP_ANONYMOUS;

                    area = mmap(vaddr, length, PROT_READ | PROT_WRITE,

                                flags, -1, 0);

#endif

                }

                if (area != vaddr) {

                    fprintf(stderr, "Could not remap addr: %lx@%lx\n",

                            length, addr);

                    exit(1);

                }

                qemu_madvise(vaddr, length, QEMU_MADV_MERGEABLE);

            }

            return;

        }

    }

}
