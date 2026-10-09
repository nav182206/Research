/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8542
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b52ae27edf392e5a0df95054d394d850b8e57d35
 */

int avio_put_str16le(AVIOContext *s, const char *str)

{

    const uint8_t *q = str;

    int ret = 0;



    while (*q) {

        uint32_t ch;

        uint16_t tmp;



        GET_UTF8(ch, *q++, break;)

        PUT_UTF16(ch, tmp, avio_wl16(s, tmp); ret += 2;)

    }

    avio_wl16(s, 0);

    ret += 2;

    return ret;

}
