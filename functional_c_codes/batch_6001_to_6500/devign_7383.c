/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7383
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b04bbe6b869581d572fe6b1dc351a2fd8e134cc1
 */

static void RENAME(mix6to2)(SAMPLE **out, const SAMPLE **in, COEFF *coeffp, integer len){

    int i;



    for(i=0; i<len; i++) {

        INTER t = in[2][i]*coeffp[0*6+2] + in[3][i]*coeffp[0*6+3];

        out[0][i] = R(t + in[0][i]*(INTER)coeffp[0*6+0] + in[4][i]*(INTER)coeffp[0*6+4]);

        out[1][i] = R(t + in[1][i]*(INTER)coeffp[1*6+1] + in[5][i]*(INTER)coeffp[1*6+5]);

    }

}
