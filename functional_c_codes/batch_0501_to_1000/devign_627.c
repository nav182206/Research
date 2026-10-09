/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_627
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ec45bbe5f1921c6553fbf9c0c76b358b0403c22d
 */

envlist_create(void)

{

	envlist_t *envlist;



	if ((envlist = malloc(sizeof (*envlist))) == NULL)

		return (NULL);



	QLIST_INIT(&envlist->el_entries);

	envlist->el_count = 0;



	return (envlist);

}
