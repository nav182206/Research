/* 
 * Benchmark Sample ID : devign_1135
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=cf48b006400e34e1177d0ca22d1cdb5c900a199a
 */

static inline int get_ue_code(GetBitContext *gb, int order)

{

    if (order) {

        int ret = get_ue_golomb(gb) << order;

        return ret + get_bits(gb, order);

    }

    return get_ue_golomb(gb);

}
