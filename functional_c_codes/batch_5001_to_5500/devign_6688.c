/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6688
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=30be1ea33e5525266ad871bed60b1893a53caeaf
 */

static int ebml_read_binary(AVIOContext *pb, int length, EbmlBin *bin)

{

    av_free(bin->data);

    if (!(bin->data = av_malloc(length)))

        return AVERROR(ENOMEM);



    bin->size = length;

    bin->pos  = avio_tell(pb);

    if (avio_read(pb, bin->data, length) != length) {

        av_freep(&bin->data);

        return AVERROR(EIO);

    }



    return 0;

}
