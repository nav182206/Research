/* 
 * Benchmark Sample ID : devign_7946
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1ad3c6abc0d67e00b84abaa5527bc64b70ca2205
 */

static pid_t qtest_qemu_pid(QTestState *s)

{

    FILE *f;

    char buffer[1024];

    pid_t pid = -1;



    f = fopen(s->pid_file, "r");

    if (f) {

        if (fgets(buffer, sizeof(buffer), f)) {

            pid = atoi(buffer);

        }

        fclose(f);

    }

    return pid;

}
