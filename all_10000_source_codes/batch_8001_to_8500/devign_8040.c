/* 
 * Benchmark Sample ID : devign_8040
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2cac260768b9d4253737417ea7501cf2950e257f
 */

static int write_elf64_load(DumpState *s, MemoryMapping *memory_mapping,

                            int phdr_index, hwaddr offset)

{

    Elf64_Phdr phdr;

    int ret;

    int endian = s->dump_info.d_endian;



    memset(&phdr, 0, sizeof(Elf64_Phdr));

    phdr.p_type = cpu_convert_to_target32(PT_LOAD, endian);

    phdr.p_offset = cpu_convert_to_target64(offset, endian);

    phdr.p_paddr = cpu_convert_to_target64(memory_mapping->phys_addr, endian);

    if (offset == -1) {

        /* When the memory is not stored into vmcore, offset will be -1 */

        phdr.p_filesz = 0;

    } else {

        phdr.p_filesz = cpu_convert_to_target64(memory_mapping->length, endian);

    }

    phdr.p_memsz = cpu_convert_to_target64(memory_mapping->length, endian);

    phdr.p_vaddr = cpu_convert_to_target64(memory_mapping->virt_addr, endian);



    ret = fd_write_vmcore(&phdr, sizeof(Elf64_Phdr), s);

    if (ret < 0) {

        dump_error(s, "dump: failed to write program header table.\n");

        return -1;

    }



    return 0;

}
