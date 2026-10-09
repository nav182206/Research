/* 
 * Benchmark Sample ID : devign_6248
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1d22d269f54cc7e44f778bb6ffee96a172eb07a1
 */

static void mxf_read_pixel_layout(AVIOContext *pb, MXFDescriptor *descriptor)

{

    int code, value, ofs = 0;

    char layout[16] = {0}; /* not for printing, may end up not terminated on purpose */



    do {

        code = avio_r8(pb);

        value = avio_r8(pb);

        av_dlog(NULL, "pixel layout: code %#x\n", code);



        if (ofs <= 14) {

            layout[ofs++] = code;

            layout[ofs++] = value;

        }

    } while (code != 0); /* SMPTE 377M E.2.46 */



    ff_mxf_decode_pixel_layout(layout, &descriptor->pix_fmt);

}
