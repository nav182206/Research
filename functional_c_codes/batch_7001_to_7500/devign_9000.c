/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9000
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0372e73f917e72c40b09270f771046fc142be4a7
 */

av_cold void ff_intrax8_common_init(IntraX8Context *w, MpegEncContext *const s)

{

    w->s = s;

    x8_vlc_init();

    assert(s->mb_width > 0);



    // two rows, 2 blocks per cannon mb

    w->prediction_table = av_mallocz(s->mb_width * 2 * 2);



    ff_init_scantable(s->idsp.idct_permutation, &w->scantable[0],

                      ff_wmv1_scantable[0]);

    ff_init_scantable(s->idsp.idct_permutation, &w->scantable[1],

                      ff_wmv1_scantable[2]);

    ff_init_scantable(s->idsp.idct_permutation, &w->scantable[2],

                      ff_wmv1_scantable[3]);



    ff_intrax8dsp_init(&w->dsp);

}
