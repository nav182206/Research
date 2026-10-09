/* 
 * Benchmark Sample ID : devign_6015
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d66b969b0d9c8eefdcbff4b48535b0fe1501d139
 */

static VTDIOTLBEntry *vtd_lookup_iotlb(IntelIOMMUState *s, uint16_t source_id,

                                       hwaddr addr)

{

    uint64_t key;



    key = (addr >> VTD_PAGE_SHIFT_4K) |

           ((uint64_t)(source_id) << VTD_IOTLB_SID_SHIFT);

    return g_hash_table_lookup(s->iotlb, &key);



}
