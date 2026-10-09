/* 
 * Benchmark Sample ID : devign_7611
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=328e203ca9b5e5afcd0769dae149075735150346
 */

static int mpegts_audio_write(void *opaque, uint8_t *buf, int size)

{

    MpegTSWriteStream *ts_st = (MpegTSWriteStream *)opaque;

    if (ts_st->adata_pos + size > ts_st->adata_size)

        return AVERROR(EIO);



    memcpy(ts_st->adata + ts_st->adata_pos, buf, size);

    ts_st->adata_pos += size;



    return 0;

}
