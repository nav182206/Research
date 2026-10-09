/* 
 * Benchmark Sample ID : devign_4109
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f3c32fce3688fe1f13ceb0777faa1fc19d66d1fc
 */

static int nbd_errno_to_system_errno(int err)

{

    switch (err) {

    case NBD_SUCCESS:

        return 0;

    case NBD_EPERM:

        return EPERM;

    case NBD_EIO:

        return EIO;

    case NBD_ENOMEM:

        return ENOMEM;

    case NBD_ENOSPC:

        return ENOSPC;

    case NBD_EINVAL:

    default:

        return EINVAL;

    }

}
