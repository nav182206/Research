/* 
 * Benchmark Sample ID : devign_2441
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b8d8720892f7912e8a2621b30ebac0e9a48e89e3
 */

monitor_read_memory (bfd_vma memaddr, bfd_byte *myaddr, int length,

                     struct disassemble_info *info)

{

    CPUDebug *s = container_of(info, CPUDebug, info);



    if (monitor_disas_is_physical) {

        cpu_physical_memory_read(memaddr, myaddr, length);

    } else {

        cpu_memory_rw_debug(s->cpu, memaddr, myaddr, length, 0);

    }

    return 0;

}
