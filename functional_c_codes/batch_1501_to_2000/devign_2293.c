/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2293
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=202a6697ba54293235ce2d7bd5724f4f461e417f
 */

static void vorbis_free_extradata(PayloadContext * data)

{

    av_free(data);

}
