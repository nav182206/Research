/* 
 * Benchmark Sample ID : devign_2431
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=83b707613181c01fd4e9d25dda6787af439d2e41
 */

static void floor_fit(vorbis_enc_context *venc, vorbis_enc_floor *fc,

                      float *coeffs, uint_fast16_t *posts, int samples)

{

    int range = 255 / fc->multiplier + 1;

    int i;

    float tot_average = 0.;

    float averages[fc->values];

    for (i = 0; i < fc->values; i++) {

        averages[i] = get_floor_average(fc, coeffs, i);

        tot_average += averages[i];

    }

    tot_average /= fc->values;

    tot_average /= venc->quality;



    for (i = 0; i < fc->values; i++) {

        int position  = fc->list[fc->list[i].sort].x;

        float average = averages[i];

        int j;



        average *= pow(tot_average / average, 0.5) * pow(1.25, position/200.); // MAGIC!

        for (j = 0; j < range - 1; j++)

            if (ff_vorbis_floor1_inverse_db_table[j * fc->multiplier] > average)

                break;

        posts[fc->list[i].sort] = j;

    }

}
