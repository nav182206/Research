/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2918
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1760048a5d21bacf0e4838da2f61b2d8db7d2866
 */

static void test_ivshmem_memdev(void)

{

    IVState state;



    /* just for the sake of checking memory-backend property */

    setup_vm_cmd(&state, "-object memory-backend-ram,size=1M,id=mb1"

                 " -device ivshmem,x-memdev=mb1", false);



    qtest_quit(state.qtest);

}
