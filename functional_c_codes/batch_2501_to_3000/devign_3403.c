/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3403
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d6478bc7e92db4669fac701d7bb8c51756b61d8a
 */

static int cpu_gdb_write_register(CPUPPCState *env, uint8_t *mem_buf, int n)

{

    if (n < 32) {

        /* gprs */

        env->gpr[n] = ldtul_p(mem_buf);

        return sizeof(target_ulong);

    } else if (n < 64) {

        /* fprs */

        if (gdb_has_xml)

            return 0;

        env->fpr[n-32] = ldfq_p(mem_buf);

        return 8;

    } else {

        switch (n) {

        case 64:

            env->nip = ldtul_p(mem_buf);

            return sizeof(target_ulong);

        case 65:

            ppc_store_msr(env, ldtul_p(mem_buf));

            return sizeof(target_ulong);

        case 66:

            {

                uint32_t cr = ldl_p(mem_buf);

                int i;

                for (i = 0; i < 8; i++)

                    env->crf[i] = (cr >> (32 - ((i + 1) * 4))) & 0xF;

                return 4;

            }

        case 67:

            env->lr = ldtul_p(mem_buf);

            return sizeof(target_ulong);

        case 68:

            env->ctr = ldtul_p(mem_buf);

            return sizeof(target_ulong);

        case 69:

            env->xer = ldtul_p(mem_buf);

            return sizeof(target_ulong);

        case 70:

            /* fpscr */

            if (gdb_has_xml)

                return 0;

            return 4;

        }

    }

    return 0;

}
