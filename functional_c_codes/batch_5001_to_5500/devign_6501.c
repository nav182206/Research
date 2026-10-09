/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6501
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=042ef4b720f5d3321d9b7eeeb2067c671d5aeefd
 */

static inline int get_chroma_qp(int chroma_qp_index_offset, int qscale){



    return chroma_qp[av_clip(qscale + chroma_qp_index_offset, 0, 51)];

}
