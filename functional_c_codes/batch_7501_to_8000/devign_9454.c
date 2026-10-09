/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9454
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=758e8e38eb582e3dc87fd55a1d234c25108a7b7f
 */

static int local_setuid(FsContext *ctx, uid_t uid)

{

    struct passwd *pw;

    gid_t groups[33];

    int ngroups;

    static uid_t cur_uid = -1;



    if (cur_uid == uid) {

        return 0;

    }



    if (setreuid(0, 0)) {

        return -1;

    }



    pw = getpwuid(uid);

    if (pw == NULL) {

        return -1;

    }



    ngroups = 33;

    if (getgrouplist(pw->pw_name, pw->pw_gid, groups, &ngroups) == -1) {

        return -1;

    }



    if (setgroups(ngroups, groups)) {

        return -1;

    }



    if (setregid(-1, pw->pw_gid)) {

        return -1;

    }



    if (setreuid(-1, uid)) {

        return -1;

    }



    cur_uid = uid;



    return 0;

}
