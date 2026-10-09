/* 
 * Benchmark Sample ID : devign_2220
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ee9f36a88eb3e2706ea659acb0ca80c414fa5d8a
 */

static int crc_write_packet(struct AVFormatContext *s, 

                            int stream_index,

                            const uint8_t *buf, int size, int64_t pts)

{

    CRCState *crc = s->priv_data;

    crc->crcval = adler32(crc->crcval, buf, size);

    return 0;

}
