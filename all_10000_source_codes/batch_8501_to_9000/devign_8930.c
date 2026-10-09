/* 
 * Benchmark Sample ID : devign_8930
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0bb5ad7a06ebcda9102357f8755d18b63f56aa29
 */

static inline void asv2_put_level(PutBitContext *pb, int level)

{

    unsigned int index = level + 31;



    if (index <= 62) {

        put_bits(pb, ff_asv2_level_tab[index][1], ff_asv2_level_tab[index][0]);

    } else {

        put_bits(pb, ff_asv2_level_tab[31][1], ff_asv2_level_tab[31][0]);

        asv2_put_bits(pb, 8, level & 0xFF);

    }

}
