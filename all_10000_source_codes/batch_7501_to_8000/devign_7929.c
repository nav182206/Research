/* 
 * Benchmark Sample ID : devign_7929
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=72370dc1149d7c90d2c2218e0d0658bee23a5bf7
 */

static void report_unavailable_features(FeatureWord w, uint32_t mask)

{

    FeatureWordInfo *f = &feature_word_info[w];

    int i;



    for (i = 0; i < 32; ++i) {

        if (1 << i & mask) {

            const char *reg = get_register_name_32(f->cpuid_reg);

            assert(reg);

            fprintf(stderr, "warning: %s doesn't support requested feature: "

                "CPUID.%02XH:%s%s%s [bit %d]\n",

                kvm_enabled() ? "host" : "TCG",

                f->cpuid_eax, reg,

                f->feat_names[i] ? "." : "",

                f->feat_names[i] ? f->feat_names[i] : "", i);

        }

    }

}
