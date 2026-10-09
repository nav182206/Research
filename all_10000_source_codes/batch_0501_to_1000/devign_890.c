/* 
 * Benchmark Sample ID : devign_890
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static uint64_t qemu_rdma_make_wrid(uint64_t wr_id, uint64_t index,

                                         uint64_t chunk)

{

    uint64_t result = wr_id & RDMA_WRID_TYPE_MASK;



    result |= (index << RDMA_WRID_BLOCK_SHIFT);

    result |= (chunk << RDMA_WRID_CHUNK_SHIFT);



    return result;

}
