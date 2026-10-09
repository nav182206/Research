/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5234
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c8057f951d64de93bfd01569c0a725baa9f94372
 */

static void handle_arg_cpu(const char *arg)

{

    cpu_model = strdup(arg);

    if (cpu_model == NULL || strcmp(cpu_model, "?") == 0) {

        /* XXX: implement xxx_cpu_list for targets that still miss it */

#if defined(cpu_list_id)

        cpu_list_id(stdout, &fprintf, "");

#elif defined(cpu_list)

        cpu_list(stdout, &fprintf); /* deprecated */

#endif

        exit(1);

    }

}
