/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6189
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static int qemu_rdma_reg_control(RDMAContext *rdma, int idx)

{

    rdma->wr_data[idx].control_mr = ibv_reg_mr(rdma->pd,

            rdma->wr_data[idx].control, RDMA_CONTROL_MAX_BUFFER,

            IBV_ACCESS_LOCAL_WRITE | IBV_ACCESS_REMOTE_WRITE);

    if (rdma->wr_data[idx].control_mr) {

        rdma->total_registrations++;

        return 0;

    }

    fprintf(stderr, "qemu_rdma_reg_control failed!\n");

    return -1;

}
