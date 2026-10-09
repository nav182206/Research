/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4815
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0dac708e2d31898ebccacdb5911b5496b1616989
 */

int ff_new_chapter(AVFormatContext *s, int id, int64_t start, int64_t end, const char *title)

{

    AVChapter *chapter = NULL;

    int i;



    for(i=0; i<s->num_chapters; i++)

        if(s->chapters[i]->id == id)

            chapter = s->chapters[i];



    if(!chapter){

        chapter= av_mallocz(sizeof(AVChapter));

        if(!chapter)

            return AVERROR(ENOMEM);

        dynarray_add(&s->chapters, &s->num_chapters, chapter);

    }

    if(chapter->title)

        av_free(chapter->title);

    if (title)

        chapter->title = av_strdup(title);

    chapter->id    = id;

    chapter->start = start;

    chapter->end = end;



    return 0;

}
