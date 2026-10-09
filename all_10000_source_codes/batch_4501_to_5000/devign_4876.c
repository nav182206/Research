/* 
 * Benchmark Sample ID : devign_4876
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7d7d975c67aaa48a6aaf1630c143a453606567b1
 */

fetchline(void)

{

	char	*p, *line = malloc(MAXREADLINESZ);



	if (!line)

		return NULL;

	printf("%s", get_prompt());

	fflush(stdout);

	if (!fgets(line, MAXREADLINESZ, stdin)) {

		free(line);

		return NULL;

	}

	p = line + strlen(line);

	if (p != line && p[-1] == '\n')

		p[-1] = '\0';

	return line;

}
