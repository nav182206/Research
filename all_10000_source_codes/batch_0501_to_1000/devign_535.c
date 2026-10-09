/* 
 * Benchmark Sample ID : devign_535
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ae100046ca32b0b83031a60d0c3cdfc5ceb9f874
 */

static int exif_decode_tag(void *logctx, GetByteContext *gbytes, int le,

                           int depth, AVDictionary **metadata)

{

    int ret, cur_pos;

    unsigned id, count;

    enum TiffTypes type;



    if (depth > 2) {

        return 0;

    }



    ff_tread_tag(gbytes, le, &id, &type, &count, &cur_pos);



    if (!bytestream2_tell(gbytes)) {

        bytestream2_seek(gbytes, cur_pos, SEEK_SET);

        return 0;

    }



    // read count values and add it metadata

    // store metadata or proceed with next IFD

    ret = ff_tis_ifd(id);

    if (ret) {

        ret = avpriv_exif_decode_ifd(logctx, gbytes, le, depth + 1, metadata);

    } else {

        const char *name = exif_get_tag_name(id);

        char *use_name   = (char*) name;



        if (!use_name) {

            use_name = av_malloc(7);

            if (!use_name) {

                return AVERROR(ENOMEM);

            }

            snprintf(use_name, 7, "0x%04X", id);

        }



        ret = exif_add_metadata(logctx, count, type, use_name, NULL,

                                gbytes, le, metadata);



        if (!name) {

            av_freep(&use_name);

        }

    }



    bytestream2_seek(gbytes, cur_pos, SEEK_SET);



    return ret;

}
