/* 
 * Benchmark Sample ID : devign_5634
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static int qemu_rdma_write(QEMUFile *f, RDMAContext *rdma,

                           uint64_t block_offset, uint64_t offset,

                           uint64_t len)

{

    uint64_t current_addr = block_offset + offset;

    uint64_t index = rdma->current_index;

    uint64_t chunk = rdma->current_chunk;

    int ret;



    /* If we cannot merge it, we flush the current buffer first. */

    if (!qemu_rdma_buffer_mergable(rdma, current_addr, len)) {

        ret = qemu_rdma_write_flush(f, rdma);

        if (ret) {

            return ret;

        }

        rdma->current_length = 0;

        rdma->current_addr = current_addr;



        ret = qemu_rdma_search_ram_block(rdma, block_offset,

                                         offset, len, &index, &chunk);

        if (ret) {

            fprintf(stderr, "ram block search failed\n");

            return ret;

        }

        rdma->current_index = index;

        rdma->current_chunk = chunk;

    }



    /* merge it */

    rdma->current_length += len;



    /* flush it if buffer is too large */

    if (rdma->current_length >= RDMA_MERGE_MAX) {

        return qemu_rdma_write_flush(f, rdma);

    }



    return 0;

}
