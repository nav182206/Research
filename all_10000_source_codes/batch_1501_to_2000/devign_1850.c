/* 
 * Benchmark Sample ID : devign_1850
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1cb0edb40b8e94e1a50ad40c40d43e34ed8435fe
 */

static void mpeg_decode_sequence_extension(MpegEncContext *s)

{

    int horiz_size_ext, vert_size_ext;

    int bit_rate_ext, vbv_buf_ext, low_delay;

    int frame_rate_ext_n, frame_rate_ext_d;



    skip_bits(&s->gb, 8); /* profil and level */

    skip_bits(&s->gb, 1); /* progressive_sequence */

    skip_bits(&s->gb, 2); /* chroma_format */

    horiz_size_ext = get_bits(&s->gb, 2);

    vert_size_ext = get_bits(&s->gb, 2);

    s->width |= (horiz_size_ext << 12);

    s->height |= (vert_size_ext << 12);

    bit_rate_ext = get_bits(&s->gb, 12);  /* XXX: handle it */

    s->bit_rate = ((s->bit_rate / 400) | (bit_rate_ext << 12)) * 400;

    skip_bits1(&s->gb); /* marker */

    vbv_buf_ext = get_bits(&s->gb, 8);

    low_delay = get_bits1(&s->gb);

    frame_rate_ext_n = get_bits(&s->gb, 2);

    frame_rate_ext_d = get_bits(&s->gb, 5);

    if (frame_rate_ext_d >= 1)

        s->frame_rate = (s->frame_rate * frame_rate_ext_n) / frame_rate_ext_d;

    dprintf("sequence extension\n");

    s->mpeg2 = 1;

}
