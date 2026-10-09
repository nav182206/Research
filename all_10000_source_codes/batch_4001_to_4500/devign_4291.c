/* 
 * Benchmark Sample ID : devign_4291
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=84dda407628e298f33d610e9e04a8b2945d24665
 */

static inline void mcdc(uint16_t *dst, uint16_t *src, int log2w, int h, int stride, int scale, int dc){

   int i;

   dc*= 0x10001;



   switch(log2w){

   case 0:

        for(i=0; i<h; i++){

            dst[0] = scale*src[0] + dc;

            if(scale) src += stride;

            dst += stride;

        }

        break;

    case 1:

        for(i=0; i<h; i++){

            LE_CENTRIC_MUL(dst, src, scale, dc);

            if(scale) src += stride;

            dst += stride;

        }

        break;

    case 2:

        for(i=0; i<h; i++){

            LE_CENTRIC_MUL(dst,     src,     scale, dc);

            LE_CENTRIC_MUL(dst + 2, src + 2, scale, dc);

            if(scale) src += stride;

            dst += stride;

        }

        break;

    case 3:

        for(i=0; i<h; i++){

            LE_CENTRIC_MUL(dst,     src,     scale, dc);

            LE_CENTRIC_MUL(dst + 2, src + 2, scale, dc);

            LE_CENTRIC_MUL(dst + 4, src + 4, scale, dc);

            LE_CENTRIC_MUL(dst + 6, src + 6, scale, dc);

            if(scale) src += stride;

            dst += stride;

        }

        break;

    default: assert(0);

    }

}
