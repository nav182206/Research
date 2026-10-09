/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_6485
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=20fa3fb93d0f3d3eab2b1f63a03168f492fae047
 */

static int get_cluster_duration(MOVTrack *track, int cluster_idx)

{

    int64_t next_dts;



    if (cluster_idx >= track->entry)

        return 0;



    if (cluster_idx + 1 == track->entry)

        next_dts = track->track_duration + track->start_dts;

    else

        next_dts = track->cluster[cluster_idx + 1].dts;



    return next_dts - track->cluster[cluster_idx].dts;

}
