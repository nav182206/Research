/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_725
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=384acbf46b70edf0d2c1648aa1a92a90bcf7057d
 */

void async_context_push(void)

{

    struct AsyncContext *new = qemu_mallocz(sizeof(*new));

    new->parent = async_context;

    new->id = async_context->id + 1;

    async_context = new;

}
