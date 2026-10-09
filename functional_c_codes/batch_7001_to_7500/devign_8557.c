/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8557
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a9f8587e152c16e943c645ff295e015384ccd76d
 */

static void write_streaminfo(FlacEncodeContext *s, uint8_t *header)

{

    PutBitContext pb;



    memset(header, 0, FLAC_STREAMINFO_SIZE);

    init_put_bits(&pb, header, FLAC_STREAMINFO_SIZE);



    /* streaminfo metadata block */

    put_bits(&pb, 16, s->avctx->frame_size);

    put_bits(&pb, 16, s->avctx->frame_size);

    put_bits(&pb, 24, 0);

    put_bits(&pb, 24, s->max_framesize);

    put_bits(&pb, 20, s->samplerate);

    put_bits(&pb, 3, s->channels-1);

    put_bits(&pb, 5, 15);       /* bits per sample - 1 */

    /* write 36-bit sample count in 2 put_bits() calls */

    put_bits(&pb, 24, (s->sample_count & 0xFFFFFF000LL) >> 12);

    put_bits(&pb, 12,  s->sample_count & 0x000000FFFLL);

    flush_put_bits(&pb);

    /* MD5 signature = 0 */

}
