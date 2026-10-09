/* 
 * Benchmark Sample ID : devign_4629
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=22b8ada7b5e0a1ef58b21cf8e481e0c2b28ce94e
 */

static void celt_pvq_search(float *X, int *y, int K, int N)

{

    int i;

    float res = 0.0f, y_norm = 0.0f, xy_norm = 0.0f;



    for (i = 0; i < N; i++)

        res += FFABS(X[i]);



    res = K/res;



    for (i = 0; i < N; i++) {

        y[i] = lrintf(res*X[i]);

        y_norm  += y[i]*y[i];

        xy_norm += y[i]*X[i];

        K -= FFABS(y[i]);

    }



    while (K) {

        int max_idx = 0, phase = FFSIGN(K);

        float max_den = 1.0f, max_num = 0.0f;

        y_norm += 1.0f;



        for (i = 0; i < N; i++) {

            float xy_new = xy_norm + 1*phase*FFABS(X[i]);

            float y_new  = y_norm  + 2*phase*FFABS(y[i]);

            xy_new = xy_new * xy_new;

            /* FIXME: the y[i] check makes the search slightly worse at Ks below 5 */

            if (y[i] && (max_den*xy_new) > (y_new*max_num)) {

                max_den = y_new;

                max_num = xy_new;

                max_idx = i;

            }

        }



        K -= phase;



        phase *= FFSIGN(X[max_idx]);

        xy_norm += 1*phase*X[max_idx];

        y_norm  += 2*phase*y[max_idx];

        y[max_idx] += phase;

    }

}
