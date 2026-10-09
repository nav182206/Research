/* 
 * Benchmark Sample ID : devign_7435
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=502d6c0a234b10f65acb0a203aedf14de70dc555
 */

static int find_tag(ByteIOContext *pb, uint32_t tag1)

{

    unsigned int tag;

    int size;



    for(;;) {

        if (url_feof(pb))

            return -1;

        tag = get_le32(pb);

        size = get_le32(pb);

        if (tag == tag1)

            break;

        url_fseek(pb, size, SEEK_CUR);

    }

    if (size < 0)

        size = 0x7fffffff;

    return size;

}
