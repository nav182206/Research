/* 
 * Benchmark Sample ID : devign_6366
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a0efbf16604770b9d805bcf210ec29942321134f
 */

bool qemu_log_in_addr_range(uint64_t addr)

{

    if (debug_regions) {

        int i = 0;

        for (i = 0; i < debug_regions->len; i++) {

            Range *range = &g_array_index(debug_regions, Range, i);

            if (addr >= range->begin && addr <= range->end - 1) {

                return true;

            }

        }

        return false;

    } else {

        return true;

    }

}
