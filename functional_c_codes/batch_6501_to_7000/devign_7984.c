/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7984
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=56a3c24ffc11955ddc7bb21362ca8069a3fc8c55
 */

static int tpm_passthrough_test_tpmdev(int fd)

{

    struct tpm_req_hdr req = {

        .tag = cpu_to_be16(TPM_TAG_RQU_COMMAND),

        .len = cpu_to_be32(sizeof(req)),

        .ordinal = cpu_to_be32(TPM_ORD_GetTicks),

    };

    struct tpm_resp_hdr *resp;

    fd_set readfds;

    int n;

    struct timeval tv = {

        .tv_sec = 1,

        .tv_usec = 0,

    };

    unsigned char buf[1024];



    n = write(fd, &req, sizeof(req));

    if (n < 0) {

        return errno;

    }

    if (n != sizeof(req)) {

        return EFAULT;

    }



    FD_ZERO(&readfds);

    FD_SET(fd, &readfds);



    /* wait for a second */

    n = select(fd + 1, &readfds, NULL, NULL, &tv);

    if (n != 1) {

        return errno;

    }



    n = read(fd, &buf, sizeof(buf));

    if (n < sizeof(struct tpm_resp_hdr)) {

        return EFAULT;

    }



    resp = (struct tpm_resp_hdr *)buf;

    /* check the header */

    if (be16_to_cpu(resp->tag) != TPM_TAG_RSP_COMMAND ||

        be32_to_cpu(resp->len) != n) {

        return EBADMSG;

    }



    return 0;

}
