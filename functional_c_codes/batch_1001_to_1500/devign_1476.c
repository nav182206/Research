/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1476
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5c843af22604edecda10d4bb89d4eede9e1bd3d0
 */

int net_slirp_smb(const char *exported_dir)

{

    struct in_addr vserver_addr = { .s_addr = 0 };



    if (legacy_smb_export) {

        fprintf(stderr, "-smb given twice\n");

        return -1;

    }

    legacy_smb_export = exported_dir;

    if (!QTAILQ_EMPTY(&slirp_stacks)) {

        return slirp_smb(QTAILQ_FIRST(&slirp_stacks), exported_dir,

                         vserver_addr);

    }

    return 0;

}
