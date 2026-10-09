/* 
 * Benchmark Sample ID : devign_6906
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fc49f22c3b735db5aaac5f98e40b7124a2be13b8
 */

static int configure_filtergraph(FilterGraph *fg)

{

    return fg->graph_desc ? configure_complex_filter(fg) : configure_video_filters(fg);

}
