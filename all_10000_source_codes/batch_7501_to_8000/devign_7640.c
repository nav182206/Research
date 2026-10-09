/* 
 * Benchmark Sample ID : devign_7640
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fb7a2bf6956173eda6f9caceef8599fa4f83500d
 */

unsigned int codec_get_tag(const CodecTag *tags, int id)

{

    while (tags->id != 0) {

        if (tags->id == id)

            return tags->tag;

        tags++;

    }

    return 0;

}
