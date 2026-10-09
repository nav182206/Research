/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_47
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8b34a9dbc3f2c0afe3450cb20b94cc30f450e77b
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

    default:

        TRACE("Squashing unexpected error %d to EINVAL", err);

        /* fallthrough */

    case NBD_EINVAL:

        return EINVAL;

    }

}
