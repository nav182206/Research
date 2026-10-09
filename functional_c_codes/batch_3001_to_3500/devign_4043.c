/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4043
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=088ed5314694031e07e02e9d364c9d486a60e704
 */

static int mkv_write_tags(AVFormatContext *s)

{

    ebml_master tags = {0};

    int i, ret;



    ff_metadata_conv_ctx(s, ff_mkv_metadata_conv, NULL);



    if (av_dict_get(s->metadata, "", NULL, AV_DICT_IGNORE_SUFFIX)) {

        ret = mkv_write_tag(s, s->metadata, 0, 0, &tags);

        if (ret < 0) return ret;

    }



    for (i = 0; i < s->nb_streams; i++) {

        AVStream *st = s->streams[i];



        if (!av_dict_get(st->metadata, "", 0, AV_DICT_IGNORE_SUFFIX))

            continue;



        ret = mkv_write_tag(s, st->metadata, MATROSKA_ID_TAGTARGETS_TRACKUID, i + 1, &tags);

        if (ret < 0) return ret;

    }



    for (i = 0; i < s->nb_chapters; i++) {

        AVChapter *ch = s->chapters[i];



        if (!av_dict_get(ch->metadata, "", NULL, AV_DICT_IGNORE_SUFFIX))

            continue;



        ret = mkv_write_tag(s, ch->metadata, MATROSKA_ID_TAGTARGETS_CHAPTERUID, ch->id, &tags);

        if (ret < 0) return ret;

    }



    if (tags.pos)

        end_ebml_master(s->pb, tags);

    return 0;

}
