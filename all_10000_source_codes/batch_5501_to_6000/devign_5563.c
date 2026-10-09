/* 
 * Benchmark Sample ID : devign_5563
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=83548fe894cdb455cc127f754d09905b6d23c173
 */

static int asf_write_trailer(AVFormatContext *s)

{

    ASFContext *asf = s->priv_data;

    int64_t file_size, data_size;



    /* flush the current packet */

    if (asf->pb.buf_ptr > asf->pb.buffer)

        flush_packet(s);



    /* write index */

    data_size = avio_tell(s->pb);

    if ((!asf->is_streamed) && (asf->nb_index_count != 0))

        asf_write_index(s, asf->index_ptr, asf->maximum_packet, asf->nb_index_count);

    avio_flush(s->pb);



    if (asf->is_streamed || !s->pb->seekable) {

        put_chunk(s, 0x4524, 0, 0); /* end of stream */

    } else {

        /* rewrite an updated header */

        file_size = avio_tell(s->pb);

        avio_seek(s->pb, 0, SEEK_SET);

        asf_write_header1(s, file_size, data_size - asf->data_offset);

    }



    av_free(asf->index_ptr);

    return 0;

}
