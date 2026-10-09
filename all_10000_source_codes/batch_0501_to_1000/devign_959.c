/* 
 * Benchmark Sample ID : devign_959
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c7e587b73ebac05943df78f5f37d80d32ff47d3d
 */

static mode_t v9mode_to_mode(uint32_t mode, V9fsString *extension)

{

    mode_t ret;



    ret = mode & 0777;

    if (mode & P9_STAT_MODE_DIR) {

        ret |= S_IFDIR;

    }



    if (mode & P9_STAT_MODE_SYMLINK) {

        ret |= S_IFLNK;

    }

    if (mode & P9_STAT_MODE_SOCKET) {

        ret |= S_IFSOCK;

    }

    if (mode & P9_STAT_MODE_NAMED_PIPE) {

        ret |= S_IFIFO;

    }

    if (mode & P9_STAT_MODE_DEVICE) {

        if (extension && extension->data[0] == 'c') {

            ret |= S_IFCHR;

        } else {

            ret |= S_IFBLK;

        }

    }



    if (!(ret&~0777)) {

        ret |= S_IFREG;

    }



    if (mode & P9_STAT_MODE_SETUID) {

        ret |= S_ISUID;

    }

    if (mode & P9_STAT_MODE_SETGID) {

        ret |= S_ISGID;

    }

    if (mode & P9_STAT_MODE_SETVTX) {

        ret |= S_ISVTX;

    }



    return ret;

}
