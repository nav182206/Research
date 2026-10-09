/* 
 * Benchmark Sample ID : devign_5702
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b9bec74bcb16519a876ec21cd5277c526a9b512d
 */

static int get_para_features(CPUState *env)

{

        int i, features = 0;



        for (i = 0; i < ARRAY_SIZE(para_features) - 1; i++) {

                if (kvm_check_extension(env->kvm_state, para_features[i].cap))

                        features |= (1 << para_features[i].feature);

        }



        return features;

}
