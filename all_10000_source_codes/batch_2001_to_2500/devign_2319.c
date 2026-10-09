/* 
 * Benchmark Sample ID : devign_2319
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bacabb0afadb47294806481a7ebb6fa5d4f1c7bd
 */

static uint64_t vtd_get_iotlb_key(uint64_t gfn, uint8_t source_id,

                                  uint32_t level)

{

    return gfn | ((uint64_t)(source_id) << VTD_IOTLB_SID_SHIFT) |

           ((uint64_t)(level) << VTD_IOTLB_LVL_SHIFT);

}
