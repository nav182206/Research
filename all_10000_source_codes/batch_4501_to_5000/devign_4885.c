/* 
 * Benchmark Sample ID : devign_4885
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1a0d9b503d2e9c4278d6e93d40873dff9d191a25
 */

static int open_next_file(AVFormatContext *avf)

{

    ConcatContext *cat = avf->priv_data;

    unsigned fileno = cat->cur_file - cat->files;



    if (cat->cur_file->duration == AV_NOPTS_VALUE)

        cat->cur_file->duration = cat->avf->duration - (cat->cur_file->file_inpoint - cat->cur_file->file_start_time);



    if (++fileno >= cat->nb_files) {

        cat->eof = 1;

        return AVERROR_EOF;

    }

    return open_file(avf, fileno);

}
