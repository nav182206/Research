/* 
 * Benchmark Sample ID : devign_8800
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=962b289ef35087fcd8764e4e29808d8ac90157f7
 */

print_syscall_ret(int num, abi_long ret)

{

    int i;



    for(i=0;i<nsyscalls;i++)

        if( scnames[i].nr == num ) {

            if( scnames[i].result != NULL ) {

                scnames[i].result(&scnames[i],ret);

            } else {

                if( ret < 0 ) {

                    gemu_log(" = -1 errno=" TARGET_ABI_FMT_ld " (%s)\n", -ret, target_strerror(-ret));

                } else {

                    gemu_log(" = " TARGET_ABI_FMT_ld "\n", ret);

                }

            }

            break;

        }

}
