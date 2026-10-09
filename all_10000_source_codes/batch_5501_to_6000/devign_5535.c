/* 
 * Benchmark Sample ID : devign_5535
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1ec83d9a9e472f485897ac92bad9631d551a8c5b
 */

static int add_metadata(const uint8_t **buf, int count, int type,

                        const char *name, const char *sep, TiffContext *s)

{

    switch(type) {

    case TIFF_DOUBLE: return add_doubles_metadata(buf, count, name, sep, s);

    case TIFF_SHORT : return add_shorts_metadata(buf, count, name, sep, s);

    default         : return AVERROR_INVALIDDATA;

    };

}
