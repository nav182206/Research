/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_4218
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=97f4ed3b71cca015e82bb601a17cd816b83fff05
 */

static int cmd_valid_while_locked(SDState *sd, SDRequest *req)

{

    /* Valid commands in locked state:

     * basic class (0)

     * lock card class (7)

     * CMD16

     * implicitly, the ACMD prefix CMD55

     * ACMD41 and ACMD42

     * Anything else provokes an "illegal command" response.

     */

    if (sd->expecting_acmd) {

        return req->cmd == 41 || req->cmd == 42;

    }

    if (req->cmd == 16 || req->cmd == 55) {

        return 1;

    }

    return sd_cmd_class[req->cmd] == 0 || sd_cmd_class[req->cmd] == 7;

}
