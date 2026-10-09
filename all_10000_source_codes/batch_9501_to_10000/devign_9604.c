/* 
 * Benchmark Sample ID : devign_9604
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7385aed20db5d83979f683b9d0048674411e963c
 */

static inline void gen_op_fcmpeq(int fccno)

{

    switch (fccno) {

    case 0:

        gen_helper_fcmpeq(cpu_env);

        break;

    case 1:

        gen_helper_fcmpeq_fcc1(cpu_env);

        break;

    case 2:

        gen_helper_fcmpeq_fcc2(cpu_env);

        break;

    case 3:

        gen_helper_fcmpeq_fcc3(cpu_env);

        break;

    }

}
