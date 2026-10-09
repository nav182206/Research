/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2314
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2c189a4e12a37b1c7cae2a2643c378c5af8f67fc
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



    if (!qtest_driver() &&

        fs.f_type != HUGETLBFS_MAGIC) {

        fprintf(stderr, "Warning: path not on HugeTLBFS: %s\n", path);

    }



    return fs.f_bsize;

}
