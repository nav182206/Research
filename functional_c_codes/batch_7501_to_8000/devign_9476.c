/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9476
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=aac46e088d67a390489af686b846dea4987d8ffb
 */

static void autocorrelate(const float x[40][2], float phi[3][2][2], int lag)

{

    int i;

    float real_sum = 0.0f;

    float imag_sum = 0.0f;

    if (lag) {

        for (i = 1; i < 38; i++) {

            real_sum += x[i][0] * x[i+lag][0] + x[i][1] * x[i+lag][1];

            imag_sum += x[i][0] * x[i+lag][1] - x[i][1] * x[i+lag][0];

        }

        phi[2-lag][1][0] = real_sum + x[ 0][0] * x[lag][0] + x[ 0][1] * x[lag][1];

        phi[2-lag][1][1] = imag_sum + x[ 0][0] * x[lag][1] - x[ 0][1] * x[lag][0];

        if (lag == 1) {

            phi[0][0][0] = real_sum + x[38][0] * x[39][0] + x[38][1] * x[39][1];

            phi[0][0][1] = imag_sum + x[38][0] * x[39][1] - x[38][1] * x[39][0];

        }

    } else {

        for (i = 1; i < 38; i++) {

            real_sum += x[i][0] * x[i][0] + x[i][1] * x[i][1];

        }

        phi[2][1][0] = real_sum + x[ 0][0] * x[ 0][0] + x[ 0][1] * x[ 0][1];

        phi[1][0][0] = real_sum + x[38][0] * x[38][0] + x[38][1] * x[38][1];

    }

}
