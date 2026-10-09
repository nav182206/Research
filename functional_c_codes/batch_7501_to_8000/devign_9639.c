/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9639
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c619ff6daf93a8f3c03decf2d3345d2474c3db91
 */

static always_inline int dv_rl2vlc_size(int run, int l)

{

    int level = (l ^ (l >> 8)) - (l >> 8);

    int size;

    

    if (run < DV_VLC_MAP_RUN_SIZE && level < DV_VLC_MAP_LEV_SIZE) {

	size = dv_vlc_map[run][level].size; 

    }

    else { 

	size = (level < DV_VLC_MAP_LEV_SIZE) ? dv_vlc_map[0][level].size : 16;

	if (run) {

	    size += (run < 16) ? dv_vlc_map[run-1][0].size : 13;

	}

    }

    return size;

}
