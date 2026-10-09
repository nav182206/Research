/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2997
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static inline int qemu_rdma_buffer_mergable(RDMAContext *rdma,

                    uint64_t offset, uint64_t len)

{

    RDMALocalBlock *block;

    uint8_t *host_addr;

    uint8_t *chunk_end;



    if (rdma->current_index < 0) {

        return 0;

    }



    if (rdma->current_chunk < 0) {

        return 0;

    }



    block = &(rdma->local_ram_blocks.block[rdma->current_index]);

    host_addr = block->local_host_addr + (offset - block->offset);

    chunk_end = ram_chunk_end(block, rdma->current_chunk);



    if (rdma->current_length == 0) {

        return 0;

    }



    /*

     * Only merge into chunk sequentially.

     */

    if (offset != (rdma->current_addr + rdma->current_length)) {

        return 0;

    }



    if (offset < block->offset) {

        return 0;

    }



    if ((offset + len) > (block->offset + block->length)) {

        return 0;

    }



    if ((host_addr + len) > chunk_end) {

        return 0;

    }



    return 1;

}
