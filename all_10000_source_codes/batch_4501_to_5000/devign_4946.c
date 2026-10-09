/* 
 * Benchmark Sample ID : devign_4946
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=155ec6edf82692bcf3a5f87d2bc697404f4e5aaf
 */

static void reset_contexts(SnowContext *s){

    int plane_index, level, orientation;



    for(plane_index=0; plane_index<2; plane_index++){

        for(level=0; level<s->spatial_decomposition_count; level++){

            for(orientation=level ? 1:0; orientation<4; orientation++){

                memset(s->plane[plane_index].band[level][orientation].state, 0, sizeof(s->plane[plane_index].band[level][orientation].state));

            }

        }

    }

    memset(s->mb_band.state, 0, sizeof(s->mb_band.state));

    memset(s->mv_band[0].state, 0, sizeof(s->mv_band[0].state));

    memset(s->mv_band[1].state, 0, sizeof(s->mv_band[1].state));

    memset(s->header_state, 0, sizeof(s->header_state));

}
