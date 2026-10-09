/* 
 * Benchmark Sample ID : devign_6796
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ec45bbe5f1921c6553fbf9c0c76b358b0403c22d
 */

envlist_to_environ(const envlist_t *envlist, size_t *count)

{

	struct envlist_entry *entry;

	char **env, **penv;



	penv = env = malloc((envlist->el_count + 1) * sizeof (char *));

	if (env == NULL)

		return (NULL);



	for (entry = envlist->el_entries.lh_first; entry != NULL;

	    entry = entry->ev_link.le_next) {

		*(penv++) = strdup(entry->ev_var);

	}

	*penv = NULL; /* NULL terminate the list */



	if (count != NULL)

		*count = envlist->el_count;



	return (env);

}
