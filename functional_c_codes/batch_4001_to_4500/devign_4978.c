/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4978
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3df18b3ed1177037892ce5b3db113d52dcdcdbf3
 */

static void rv34_gen_vlc(const uint8_t *bits, int size, VLC *vlc, const uint8_t *insyms,

                         const int num)

{

    int i;

    int counts[17] = {0}, codes[17];

    uint16_t cw[size], syms[size];

    uint8_t bits2[size];

    int maxbits = 0, realsize = 0;



    for(i = 0; i < size; i++){

        if(bits[i]){

            bits2[realsize] = bits[i];

            syms[realsize] = insyms ? insyms[i] : i;

            realsize++;

            maxbits = FFMAX(maxbits, bits[i]);

            counts[bits[i]]++;

        }

    }



    codes[0] = 0;

    for(i = 0; i < 16; i++)

        codes[i+1] = (codes[i] + counts[i]) << 1;

    for(i = 0; i < realsize; i++)

        cw[i] = codes[bits2[i]]++;



    vlc->table = &table_data[table_offs[num]];

    vlc->table_allocated = table_offs[num + 1] - table_offs[num];

    init_vlc_sparse(vlc, FFMIN(maxbits, 9), realsize,

                    bits2, 1, 1,

                    cw,    2, 2,

                    syms,  2, 2, INIT_VLC_USE_NEW_STATIC);

}
