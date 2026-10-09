/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9595
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=073c2593c9f0aa4445a6fc1b9b24e6e52a8cc2c1
 */

static void init_vlcs(FourXContext *f){

    static int done = 0;

    int i;



    if (!done) {

        done = 1;



        for(i=0; i<4; i++){

            init_vlc(&block_type_vlc[i], BLOCK_TYPE_VLC_BITS, 7, 

                     &block_type_tab[i][0][1], 2, 1,

                     &block_type_tab[i][0][0], 2, 1);

        }

    }

}
