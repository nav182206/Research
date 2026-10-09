/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6406
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b8d834a00fa3ed4dad7d371e1a00938a126a54a0
 */

static int x86_cpu_filter_features(X86CPU *cpu)

{

    CPUX86State *env = &cpu->env;

    FeatureWord w;

    int rv = 0;



    for (w = 0; w < FEATURE_WORDS; w++) {

        uint32_t host_feat =

            x86_cpu_get_supported_feature_word(w, false);

        uint32_t requested_features = env->features[w];

        env->features[w] &= host_feat;

        cpu->filtered_features[w] = requested_features & ~env->features[w];

        if (cpu->filtered_features[w]) {

            rv = 1;

        }

    }



    return rv;

}
