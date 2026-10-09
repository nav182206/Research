/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8489
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0ccabeeaef77e240f2a44f78271a8914a23e239b
 */

char *ff_get_ref_perms_string(char *buf, size_t buf_size, int perms)

{

    snprintf(buf, buf_size, "%s%s%s%s%s",

             perms & AV_PERM_READ      ? "r" : "",

             perms & AV_PERM_WRITE     ? "w" : "",

             perms & AV_PERM_PRESERVE  ? "p" : "",

             perms & AV_PERM_REUSE     ? "u" : "",

             perms & AV_PERM_REUSE2    ? "U" : "");

    return buf;

}
