/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7588
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7cc84d241ba6ef8e27e4d057176a4ad385ad3d59
 */

static void decode_rowskip(uint8_t* plane, int width, int height, int stride, VC9Context *v){

    int x, y;

    GetBitContext *gb = &v->s.gb;



    for (y=0; y<height; y++){

        if (!get_bits(gb, 1)) //rowskip

            memset(plane, 0, width);

        else

            for (x=0; x<width; x++) 

                plane[x] = get_bits(gb, 1);

        plane += stride;

    }

}
