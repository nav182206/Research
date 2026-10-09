/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_174
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4a1418e07bdcfaa3177739e04707ecaec75d89e1
 */

static void restore_native_fp_frstor(CPUState *env)

{

    int fptag, i, j;

    struct fpstate fp1, *fp = &fp1;



    fp->fpuc = env->fpuc;

    fp->fpus = (env->fpus & ~0x3800) | (env->fpstt & 0x7) << 11;

    fptag = 0;

    for (i=7; i>=0; i--) {

	fptag <<= 2;

	if (env->fptags[i]) {

            fptag |= 3;

        } else {

            /* the FPU automatically computes it */

        }

    }

    fp->fptag = fptag;

    j = env->fpstt;

    for(i = 0;i < 8; i++) {

        memcpy(&fp->fpregs1[i * 10], &env->fpregs[j].d, 10);

        j = (j + 1) & 7;

    }

    asm volatile ("frstor %0" : "=m" (*fp));

}
