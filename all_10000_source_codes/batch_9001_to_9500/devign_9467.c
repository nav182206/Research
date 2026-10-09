/* 
 * Benchmark Sample ID : devign_9467
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=24ac07dec7f23c58dc48aa7754f872781b386d46
 */

static void slirp_smb_cleanup(SlirpState *s)

{

    char cmd[128];

    int ret;



    if (s->smb_dir[0] != '\0') {

        snprintf(cmd, sizeof(cmd), "rm -rf %s", s->smb_dir);

        ret = system(cmd);

        if (!WIFEXITED(ret)) {

            qemu_error("'%s' failed.\n", cmd);

        } else if (WEXITSTATUS(ret)) {

            qemu_error("'%s' failed. Error code: %d\n",

                    cmd, WEXITSTATUS(ret));

        }

        s->smb_dir[0] = '\0';

    }

}
