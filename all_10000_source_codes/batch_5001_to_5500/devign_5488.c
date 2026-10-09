/* 
 * Benchmark Sample ID : devign_5488
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=01a720125f5e2f0a23d2682b39dead2fcc820066
 */

void helper_movcal(CPUSH4State *env, uint32_t address, uint32_t value)

{

    if (cpu_sh4_is_cached (env, address))

    {

	memory_content *r = malloc (sizeof(memory_content));

	r->address = address;

	r->value = value;

	r->next = NULL;



	*(env->movcal_backup_tail) = r;

	env->movcal_backup_tail = &(r->next);

    }

}
