/* 
 * Benchmark Sample ID : devign_3560
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=44ed34b79097b972095e7c9efae32a13b4bc51dc
 */

static int avi_load_index(AVFormatContext *s)

{

    AVIContext *avi = s->priv_data;

    ByteIOContext *pb = s->pb;

    uint32_t tag, size;

    int64_t pos= url_ftell(pb);



    url_fseek(pb, avi->movi_end, SEEK_SET);

#ifdef DEBUG_SEEK

    printf("movi_end=0x%"PRIx64"\n", avi->movi_end);

#endif

    for(;;) {

        if (url_feof(pb))

            break;

        tag = get_le32(pb);

        size = get_le32(pb);

#ifdef DEBUG_SEEK

        printf("tag=%c%c%c%c size=0x%x\n",

               tag & 0xff,

               (tag >> 8) & 0xff,

               (tag >> 16) & 0xff,

               (tag >> 24) & 0xff,

               size);

#endif

        switch(tag) {

        case MKTAG('i', 'd', 'x', '1'):

            if (avi_read_idx1(s, size) < 0)

                goto skip;

            else

                goto the_end;

            break;

        default:

        skip:

            size += (size & 1);

            url_fskip(pb, size);

            break;

        }

    }

 the_end:

    url_fseek(pb, pos, SEEK_SET);

    return 0;

}
