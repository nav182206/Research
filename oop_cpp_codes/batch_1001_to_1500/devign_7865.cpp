/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7865
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a83000f5e3fac30a7f213af1ba6a8f827622854d
 */

void *kvmppc_create_spapr_tce(uint32_t liobn, uint32_t window_size, int *pfd)

{

    struct kvm_create_spapr_tce args = {

        .liobn = liobn,

        .window_size = window_size,

    };

    long len;

    int fd;

    void *table;



    /* Must set fd to -1 so we don't try to munmap when called for

     * destroying the table, which the upper layers -will- do

     */

    *pfd = -1;

    if (!cap_spapr_tce) {

        return NULL;

    }



    fd = kvm_vm_ioctl(kvm_state, KVM_CREATE_SPAPR_TCE, &args);

    if (fd < 0) {

        fprintf(stderr, "KVM: Failed to create TCE table for liobn 0x%x\n",

                liobn);

        return NULL;

    }



    len = (window_size / SPAPR_TCE_PAGE_SIZE) * sizeof(sPAPRTCE);

    /* FIXME: round this up to page size */



    table = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

    if (table == MAP_FAILED) {

        fprintf(stderr, "KVM: Failed to map TCE table for liobn 0x%x\n",

                liobn);

        close(fd);

        return NULL;

    }



    *pfd = fd;

    return table;

}
