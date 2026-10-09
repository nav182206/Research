/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7851
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6ab3fc32ea640026726bc5f9f4db622d0954fb8a
 */

ssize_t slirp_send(struct socket *so, const void *buf, size_t len, int flags)

{

    if (so->s == -1 && so->extra) {

        qemu_chr_fe_write(so->extra, buf, len);

        return len;

    }



    return send(so->s, buf, len, flags);

}
