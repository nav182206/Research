/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2624
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fb7a2bf6956173eda6f9caceef8599fa4f83500d
 */

static unsigned int codec_get_asf_tag(const CodecTag *tags, unsigned int id)

{

    while (tags->id != 0) {

        if (!tags->invalid_asf && tags->id == id)

            return tags->tag;

        tags++;

    }

    return 0;

}
