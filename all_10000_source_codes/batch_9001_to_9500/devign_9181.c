/* 
 * Benchmark Sample ID : devign_9181
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=465e1dadbef7596a3eb87089a66bb4ecdc26d3c4
 */

void init_checksum(ByteIOContext *s, unsigned long (*update_checksum)(unsigned long c, const uint8_t *p, unsigned int len), unsigned long checksum){

    s->update_checksum= update_checksum;

    s->checksum= s->update_checksum(checksum, NULL, 0);

    s->checksum_ptr= s->buf_ptr;

}
