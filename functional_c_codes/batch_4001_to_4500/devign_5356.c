/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5356
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=83548fe894cdb455cc127f754d09905b6d23c173
 */

static int aiff_write_trailer(AVFormatContext *s)

{

    AVIOContext *pb = s->pb;

    AIFFOutputContext *aiff = s->priv_data;

    AVCodecParameters *par = s->streams[0]->codecpar;



    /* Chunks sizes must be even */

    int64_t file_size, end_size;

    end_size = file_size = avio_tell(pb);

    if (file_size & 1) {

        avio_w8(pb, 0);

        end_size++;

    }



    if (s->pb->seekable) {

        /* File length */

        avio_seek(pb, aiff->form, SEEK_SET);

        avio_wb32(pb, file_size - aiff->form - 4);



        /* Number of sample frames */

        avio_seek(pb, aiff->frames, SEEK_SET);

        avio_wb32(pb, (file_size - aiff->ssnd - 12) / par->block_align);



        /* Sound Data chunk size */

        avio_seek(pb, aiff->ssnd, SEEK_SET);

        avio_wb32(pb, file_size - aiff->ssnd - 4);



        /* return to the end */

        avio_seek(pb, end_size, SEEK_SET);



        avio_flush(pb);

    }



    return 0;

}
