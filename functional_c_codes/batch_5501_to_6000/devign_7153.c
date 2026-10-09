/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7153
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8976ef7aec4c62e41a0abb50d2bf4dbfa3508e2a
 */

static int add_file(AVFormatContext *avf, char *filename, ConcatFile **rfile,

                    unsigned *nb_files_alloc)

{

    ConcatContext *cat = avf->priv_data;

    ConcatFile *file;

    char *url;

    size_t url_len;



    url_len = strlen(avf->filename) + strlen(filename) + 16;

    if (!(url = av_malloc(url_len)))

        return AVERROR(ENOMEM);

    ff_make_absolute_url(url, url_len, avf->filename, filename);

    av_free(filename);



    if (cat->nb_files >= *nb_files_alloc) {

        unsigned n = FFMAX(*nb_files_alloc * 2, 16);

        ConcatFile *new_files;

        if (n <= cat->nb_files || n > SIZE_MAX / sizeof(*cat->files) ||

            !(new_files = av_realloc(cat->files, n * sizeof(*cat->files))))

            return AVERROR(ENOMEM);

        cat->files = new_files;

        *nb_files_alloc = n;

    }



    file = &cat->files[cat->nb_files++];

    memset(file, 0, sizeof(*file));

    *rfile = file;



    file->url        = url;

    file->start_time = AV_NOPTS_VALUE;

    file->duration   = AV_NOPTS_VALUE;



    return 0;

}
