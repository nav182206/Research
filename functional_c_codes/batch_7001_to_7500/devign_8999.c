/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8999
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7464f0587b2938a3e10e9f995f384df8a5f298ac
 */

static QString *read_line(FILE *file, char *key)

{

    char value[128];



    if (fscanf(file, "%s%s", key, value) == EOF)

        return NULL;

    remove_dots(key);

    return qstring_from_str(value);

}
