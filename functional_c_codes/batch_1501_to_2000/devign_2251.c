/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2251
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=daa1ea049a9445b7bed03963cb789497065dd1eb
 */

void ff_vp3_h_loop_filter_mmx(uint8_t *src, int stride, int *bounding_values)

{

    x86_reg tmp;



    __asm__ volatile(

        "movd -2(%1),      %%mm6 \n\t"

        "movd -2(%1,%3),   %%mm0 \n\t"

        "movd -2(%1,%3,2), %%mm1 \n\t"

        "movd -2(%1,%4),   %%mm4 \n\t"



        TRANSPOSE8x4(%%mm6, %%mm0, %%mm1, %%mm4, -2(%2), -2(%2,%3), -2(%2,%3,2), -2(%2,%4), %%mm2)

        VP3_LOOP_FILTER(%5)

        SBUTTERFLY(%%mm4, %%mm3, %%mm5, bw, q)



        STORE_4_WORDS((%1), (%1,%3), (%1,%3,2), (%1,%4), %%mm4)

        STORE_4_WORDS((%2), (%2,%3), (%2,%3,2), (%2,%4), %%mm5)



        : "=&r"(tmp)

        : "r"(src), "r"(src+4*stride), "r"((x86_reg)stride), "r"((x86_reg)3*stride),

          "m"(*(uint64_t*)(bounding_values+129))

        : "memory"

    );

}
