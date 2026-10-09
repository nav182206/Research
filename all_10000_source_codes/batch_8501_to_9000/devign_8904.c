/* 
 * Benchmark Sample ID : devign_8904
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=40a7700b82aec0036622f8673ce64e070a520891
 */

static int flac_write_block_comment(AVIOContext *pb, AVDictionary **m,

                                    int last_block, int bitexact)

{

    const char *vendor = bitexact ? "ffmpeg" : LIBAVFORMAT_IDENT;

    unsigned int len;

    uint8_t *p, *p0;



    ff_metadata_conv(m, ff_vorbiscomment_metadata_conv, NULL);



    len = ff_vorbiscomment_length(*m, vendor);

    p0 = av_malloc(len+4);

    if (!p0)

        return AVERROR(ENOMEM);

    p = p0;



    bytestream_put_byte(&p, last_block ? 0x84 : 0x04);

    bytestream_put_be24(&p, len);

    ff_vorbiscomment_write(&p, m, vendor);



    avio_write(pb, p0, len+4);

    av_freep(&p0);

    p = NULL;



    return 0;

}
