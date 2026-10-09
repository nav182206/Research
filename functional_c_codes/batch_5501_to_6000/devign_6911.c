/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6911
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static int qemu_rdma_registration_start(QEMUFile *f, void *opaque,

                                        uint64_t flags)

{

    QEMUFileRDMA *rfile = opaque;

    RDMAContext *rdma = rfile->rdma;



    CHECK_ERROR_STATE();



    DDDPRINTF("start section: %" PRIu64 "\n", flags);

    qemu_put_be64(f, RAM_SAVE_FLAG_HOOK);

    qemu_fflush(f);



    return 0;

}
