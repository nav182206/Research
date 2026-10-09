/* 
 * Benchmark Sample ID : devign_1331
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ec45bbe5f1921c6553fbf9c0c76b358b0403c22d
 */

envlist_unsetenv(envlist_t *envlist, const char *env)

{

	struct envlist_entry *entry;

	size_t envname_len;



	if ((envlist == NULL) || (env == NULL))

		return (EINVAL);



	/* env is not allowed to contain '=' */

	if (strchr(env, '=') != NULL)

		return (EINVAL);



	/*

	 * Find out the requested entry and remove

	 * it from the list.

	 */

	envname_len = strlen(env);

	for (entry = envlist->el_entries.lh_first; entry != NULL;

	    entry = entry->ev_link.le_next) {

		if (strncmp(entry->ev_var, env, envname_len) == 0)

			break;

	}

	if (entry != NULL) {

		QLIST_REMOVE(entry, ev_link);

		free((char *)entry->ev_var);

		free(entry);



		envlist->el_count--;

	}

	return (0);

}
