/* 
 * Benchmark Sample ID : devign_3153
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5d7e3d71673d64a16b58430a0027afadb6b3a54e
 */

static const unsigned char *seq_decode_op3(SeqVideoContext *seq, const unsigned char *src, unsigned char *dst)

{

    int pos, offset;



    do {

        pos = *src++;

        offset = ((pos >> 3) & 7) * seq->frame.linesize[0] + (pos & 7);

        dst[offset] = *src++;

    } while (!(pos & 0x80));



    return src;

}
