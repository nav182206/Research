/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1247
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5d7e3d71673d64a16b58430a0027afadb6b3a54e
 */

static const unsigned char *seq_decode_op2(SeqVideoContext *seq, const unsigned char *src, unsigned char *dst)

{

    int i;



    for (i = 0; i < 8; i++) {

        memcpy(dst, src, 8);

        src += 8;

        dst += seq->frame.linesize[0];

    }



    return src;

}
