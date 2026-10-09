/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_665
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e612a1f7256bb3546cf3e9ae6cad3997c4153663
 */

target_read_memory (bfd_vma memaddr,

                    bfd_byte *myaddr,

                    int length,

                    struct disassemble_info *info)

{

    int i;

    for(i = 0; i < length; i++) {

        myaddr[i] = ldub_code(memaddr + i);

    }

    return 0;

}
