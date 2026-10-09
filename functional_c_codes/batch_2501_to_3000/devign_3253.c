/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3253
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5ff998a233d759d0de83ea6f95c383d03d25d88e
 */

static void calc_sums(int pmin, int pmax, uint32_t *data, int n, int pred_order,

                      uint32_t sums[][MAX_PARTITIONS])

{

    int i, j;

    int parts;

    uint32_t *res, *res_end;



    /* sums for highest level */

    parts   = (1 << pmax);

    res     = &data[pred_order];

    res_end = &data[n >> pmax];

    for (i = 0; i < parts; i++) {

        uint32_t sum = 0;

        while (res < res_end)

            sum += *(res++);

        sums[pmax][i] = sum;

        res_end += n >> pmax;

    }

    /* sums for lower levels */

    for (i = pmax - 1; i >= pmin; i--) {

        parts = (1 << i);

        for (j = 0; j < parts; j++)

            sums[i][j] = sums[i+1][2*j] + sums[i+1][2*j+1];

    }

}
