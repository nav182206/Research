/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1370
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=302a0d3ed721e4c30c6a2a37f64c60b50ffd33b9
 */

static struct iovec *cap_sg(struct iovec *sg, int cap, int *cnt)

{

    int i;

    int total = 0;



    for (i = 0; i < *cnt; i++) {

        if ((total + sg[i].iov_len) > cap) {

            sg[i].iov_len -= ((total + sg[i].iov_len) - cap);

            i++;

            break;

        }

        total += sg[i].iov_len;

    }



    *cnt = i;



    return sg;

}
