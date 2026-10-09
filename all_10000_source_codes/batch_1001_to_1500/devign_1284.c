/* 
 * Benchmark Sample ID : devign_1284
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cc276c85d15272df6e44fb3252657a43cbd49555
 */

static int64_t truehd_layout(int chanmap)

{

    int layout = 0, i;



    for (i = 0; i < 13; i++)

        layout |= thd_layout[i] * ((chanmap >> i) & 1);



    return layout;

}
