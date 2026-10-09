/* 
 * Benchmark Sample ID : devign_1753
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=57d1f6d7ce23e79a8ebe4a57bd2363b269b4664b
 */

size_t qemu_fd_getpagesize(int fd)

{

#ifdef CONFIG_LINUX

    struct statfs fs;

    int ret;



    if (fd != -1) {

        do {

            ret = fstatfs(fd, &fs);

        } while (ret != 0 && errno == EINTR);



        if (ret == 0 && fs.f_type == HUGETLBFS_MAGIC) {

            return fs.f_bsize;

        }

    }








    return getpagesize();

}
