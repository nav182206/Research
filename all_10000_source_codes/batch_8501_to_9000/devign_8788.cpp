/* 
 * Benchmark Sample ID : devign_8788
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d66b969b0d9c8eefdcbff4b48535b0fe1501d139
 */

static gboolean vtd_hash_remove_by_page(gpointer key, gpointer value,

                                        gpointer user_data)

{

    VTDIOTLBEntry *entry = (VTDIOTLBEntry *)value;

    VTDIOTLBPageInvInfo *info = (VTDIOTLBPageInvInfo *)user_data;

    uint64_t gfn = info->gfn & info->mask;

    return (entry->domain_id == info->domain_id) &&

            ((entry->gfn & info->mask) == gfn);

}
