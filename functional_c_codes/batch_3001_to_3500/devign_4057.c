/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4057
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a1f48480497bb462c5d1d589ae393335f50b06e0
 */

static float ssim_end4(int sum0[5][4], int sum1[5][4], int width)

{

    float ssim = 0.0;

    int i;



    for (i = 0; i < width; i++)

        ssim += ssim_end1(sum0[i][0] + sum0[i + 1][0] + sum1[i][0] + sum1[i + 1][0],

                          sum0[i][1] + sum0[i + 1][1] + sum1[i][1] + sum1[i + 1][1],

                          sum0[i][2] + sum0[i + 1][2] + sum1[i][2] + sum1[i + 1][2],

                          sum0[i][3] + sum0[i + 1][3] + sum1[i][3] + sum1[i + 1][3]);

    return ssim;

}
