/* 
 * Benchmark Sample ID : devign_6332
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=af19f78f2fe2b969104d4419efd25fdee90a2814
 */

void dsputil_init_mmi(void)

{

    clear_blocks = clear_blocks_mmi;

    

    put_pixels_tab[1][0] = put_pixels8_mmi;

    put_no_rnd_pixels_tab[1][0] = put_pixels8_mmi;

    

    put_pixels_tab[0][0] = put_pixels16_mmi;

    put_no_rnd_pixels_tab[0][0] = put_pixels16_mmi;

    

    get_pixels = get_pixels_mmi;

}
