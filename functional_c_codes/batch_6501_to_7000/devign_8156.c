/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8156
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=68e75e4dec6b5f46a190118eecbba1e95c396e3d
 */

static void floor_fit(venc_context_t * venc, floor_t * fc, float * coeffs, int * posts, int samples) {

    int range = 255 / fc->multiplier + 1;

    int i;

    for (i = 0; i < fc->values; i++) {

        int position = fc->list[fc->list[i].sort].x;

        int begin = fc->list[fc->list[FFMAX(i-1, 0)].sort].x;

        int end   = fc->list[fc->list[FFMIN(i+1, fc->values - 1)].sort].x;

        int j;

        float average = 0;

        begin = (position + begin) / 2;

        end   = (position + end  ) / 2;



        assert(end <= samples);

        for (j = begin; j < end; j++) average += fabs(coeffs[j]);

        average /= end - begin;

        average /= 32; // MAGIC!

        for (j = 0; j < range - 1; j++) if (floor1_inverse_db_table[j * fc->multiplier] > average) break;

        posts[fc->list[i].sort] = j;

    }

}
