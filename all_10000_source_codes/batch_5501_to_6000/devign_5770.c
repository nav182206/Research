/* 
 * Benchmark Sample ID : devign_5770
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8b19ae07616bbd18969b94cbf5d74308a8f2bbdf
 */

int av_crc_init(AVCRC *ctx, int le, int bits, uint32_t poly, int ctx_size){

    int i, j;

    uint32_t c;



    if (bits < 8 || bits > 32 || poly >= (1LL<<bits))

        return -1;

    if (ctx_size != sizeof(AVCRC)*257 && ctx_size != sizeof(AVCRC)*1024)

        return -1;



    for (i = 0; i < 256; i++) {

        if (le) {

            for (c = i, j = 0; j < 8; j++)

                c = (c>>1)^(poly & (-(c&1)));

            ctx[i] = c;

        } else {

            for (c = i << 24, j = 0; j < 8; j++)

                c = (c<<1) ^ ((poly<<(32-bits)) & (((int32_t)c)>>31) );

            ctx[i] = av_bswap32(c);

        }

    }

    ctx[256]=1;

#if !CONFIG_SMALL

    if(ctx_size >= sizeof(AVCRC)*1024)

        for (i = 0; i < 256; i++)

            for(j=0; j<3; j++)

                ctx[256*(j+1) + i]= (ctx[256*j + i]>>8) ^ ctx[ ctx[256*j + i]&0xFF ];

#endif



    return 0;

}
