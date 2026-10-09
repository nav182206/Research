/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3888
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e33d3720239314d28a48c64c1071ba9c048280d1
 */

static void ffm_set_write_index(AVFormatContext *s, int64_t pos,

                                int64_t file_size)

{

    FFMContext *ffm = s->priv_data;

    ffm->write_index = pos;

    ffm->file_size = file_size;

}
