/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6207
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=66453b1fba6c68f2f7f5117355d34b5f40910327
 */

static void mov_parse_stsd_video(MOVContext *c, AVIOContext *pb,

                                 AVStream *st, MOVStreamContext *sc)

{

    uint8_t codec_name[32];

    int64_t stsd_start;

    unsigned int len;



    /* The first 16 bytes of the video sample description are already

     * read in ff_mov_read_stsd_entries() */

    stsd_start = avio_tell(pb) - 16;



    avio_rb16(pb); /* version */

    avio_rb16(pb); /* revision level */

    avio_rb32(pb); /* vendor */

    avio_rb32(pb); /* temporal quality */

    avio_rb32(pb); /* spatial quality */



    st->codecpar->width  = avio_rb16(pb); /* width */

    st->codecpar->height = avio_rb16(pb); /* height */



    avio_rb32(pb); /* horiz resolution */

    avio_rb32(pb); /* vert resolution */

    avio_rb32(pb); /* data size, always 0 */

    avio_rb16(pb); /* frames per samples */



    len = avio_r8(pb); /* codec name, pascal string */

    if (len > 31)

        len = 31;

    mov_read_mac_string(c, pb, len, codec_name, sizeof(codec_name));

    if (len < 31)

        avio_skip(pb, 31 - len);



    if (codec_name[0])

        av_dict_set(&st->metadata, "encoder", codec_name, 0);



    /* codec_tag YV12 triggers an UV swap in rawdec.c */

    if (!memcmp(codec_name, "Planar Y'CbCr 8-bit 4:2:0", 25)) {

        st->codecpar->codec_tag = MKTAG('I', '4', '2', '0');

        st->codecpar->width &= ~1;

        st->codecpar->height &= ~1;

    }

    /* Flash Media Server uses tag H.263 with Sorenson Spark */

    if (st->codecpar->codec_tag == MKTAG('H','2','6','3') &&

        !memcmp(codec_name, "Sorenson H263", 13))

        st->codecpar->codec_id = AV_CODEC_ID_FLV1;



    st->codecpar->bits_per_coded_sample = avio_rb16(pb); /* depth */



    avio_seek(pb, stsd_start, SEEK_SET);



    if (ff_get_qtpalette(st->codecpar->codec_id, pb, sc->palette)) {

        st->codecpar->bits_per_coded_sample &= 0x1F;

        sc->has_palette = 1;

    }

}
