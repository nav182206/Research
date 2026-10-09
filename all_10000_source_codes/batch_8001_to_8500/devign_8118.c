/* 
 * Benchmark Sample ID : devign_8118
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fd97fd4408040a9a6dfaf2fdaeca1c566db6d0aa
 */

static long gethugepagesize(const char *path, Error **errp)

{

    struct statfs fs;

    int ret;



    do {

        ret = statfs(path, &fs);

    } while (ret != 0 && errno == EINTR);



    if (ret != 0) {

        error_setg_errno(errp, errno, "failed to get page size of file %s",

                         path);

        return 0;

    }



    return fs.f_bsize;

}
