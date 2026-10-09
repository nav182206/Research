/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3601
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=01a720125f5e2f0a23d2682b39dead2fcc820066
 */

void helper_discard_movcal_backup(CPUSH4State *env)

{

    memory_content *current = env->movcal_backup;



    while(current)

    {

	memory_content *next = current->next;

	free (current);

	env->movcal_backup = current = next;

	if (current == NULL)

	    env->movcal_backup_tail = &(env->movcal_backup);

    } 

}
