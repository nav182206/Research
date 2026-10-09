/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2333
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=212c6a1d70df011b6f2a2aa02f7677503287bd00
 */

static void build_basic_mjpeg_vlc(MJpegDecodeContext *s)

{

    build_vlc(&s->vlcs[0][0], avpriv_mjpeg_bits_dc_luminance,

              avpriv_mjpeg_val_dc, 12, 0, 0);

    build_vlc(&s->vlcs[0][1], avpriv_mjpeg_bits_dc_chrominance,

              avpriv_mjpeg_val_dc, 12, 0, 0);

    build_vlc(&s->vlcs[1][0], avpriv_mjpeg_bits_ac_luminance,

              avpriv_mjpeg_val_ac_luminance, 251, 0, 1);

    build_vlc(&s->vlcs[1][1], avpriv_mjpeg_bits_ac_chrominance,

              avpriv_mjpeg_val_ac_chrominance, 251, 0, 1);

    build_vlc(&s->vlcs[2][0], avpriv_mjpeg_bits_ac_luminance,

              avpriv_mjpeg_val_ac_luminance, 251, 0, 0);

    build_vlc(&s->vlcs[2][1], avpriv_mjpeg_bits_ac_chrominance,

              avpriv_mjpeg_val_ac_chrominance, 251, 0, 0);

}
