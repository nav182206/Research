/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8121
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=15d61692da651fc79b3fc40050b986c5a73055c0
 */

static int configuration_post_load(void *opaque, int version_id)

{

    SaveState *state = opaque;

    const char *current_name = MACHINE_GET_CLASS(current_machine)->name;



    if (strncmp(state->name, current_name, state->len) != 0) {

        error_report("Machine type received is '%s' and local is '%s'",

                     state->name, current_name);

        return -EINVAL;

    }

    return 0;

}
