/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9504
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=be2960baae07e5257cde8c814cbd91647e235147
 */

static void core_prop_set_core_id(Object *obj, Visitor *v, const char *name,
                                  void *opaque, Error **errp)
{
    CPUCore *core = CPU_CORE(obj);
    Error *local_err = NULL;
    int64_t value;
    visit_type_int(v, name, &value, &local_err);
    if (local_err) {
        error_propagate(errp, local_err);
    core->core_id = value;
