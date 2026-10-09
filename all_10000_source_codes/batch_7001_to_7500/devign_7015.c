/* 
 * Benchmark Sample ID : devign_7015
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2820c9dfaa1f4093fea471665fdbef9ca7080bcd
 */

static void process_param(float *bc, EqParameter *param, float fs)

{

    int i;



    for (i = 0; i <= NBANDS; i++) {

        param[i].lower = i == 0 ? 0 : bands[i - 1];

        param[i].upper = i == NBANDS - 1 ? fs : bands[i];

        param[i].gain  = bc[i];

    }

}
