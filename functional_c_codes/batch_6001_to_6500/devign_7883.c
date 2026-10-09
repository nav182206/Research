/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7883
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=465e1dadbef7596a3eb87089a66bb4ecdc26d3c4
 */

static void update(NUTContext *nut, int stream_index, int64_t frame_start, int frame_type, int frame_code, int key_frame, int size, int64_t pts){

    StreamContext *stream= &nut->stream[stream_index];

    

    stream->last_key_frame= key_frame;

    nut->last_frame_start[ frame_type ]= frame_start;

    update_lru(stream->lru_pts_delta, pts - stream->last_pts, 3);

    update_lru(stream->lru_size     ,                   size, 2);

    stream->last_pts= pts;

    if(    nut->frame_code[frame_code].flags & FLAG_PTS 

        && nut->frame_code[frame_code].flags & FLAG_FULL_PTS)

        stream->last_full_pts= pts;

}
