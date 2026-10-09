/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9184
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=13c56e9a9cf18f33bcbc2dc1a5cf2a5f98ca9702
 */

static int decode_i_block(FourXContext *f, int16_t *block)

{

    int code, i, j, level, val;



    if (get_bits_left(&f->gb) < 2){

        av_log(f->avctx, AV_LOG_ERROR, "%d bits left before decode_i_block()\n", get_bits_left(&f->gb));

        return -1;

    }



    /* DC coef */

    val = get_vlc2(&f->pre_gb, f->pre_vlc.table, ACDC_VLC_BITS, 3);

    if (val >> 4)

        av_log(f->avctx, AV_LOG_ERROR, "error dc run != 0\n");



    if (val)

        val = get_xbits(&f->gb, val);



    val        = val * dequant_table[0] + f->last_dc;

    f->last_dc = block[0] = val;

    /* AC coefs */

    i = 1;

    for (;;) {

        code = get_vlc2(&f->pre_gb, f->pre_vlc.table, ACDC_VLC_BITS, 3);



        /* EOB */

        if (code == 0)

            break;

        if (code == 0xf0) {

            i += 16;

        } else {

            level = get_xbits(&f->gb, code & 0xf);

            i    += code >> 4;

            if (i >= 64) {

                av_log(f->avctx, AV_LOG_ERROR, "run %d oveflow\n", i);

                return 0;

            }



            j = ff_zigzag_direct[i];

            block[j] = level * dequant_table[j];

            i++;

            if (i >= 64)

                break;

        }

    }



    return 0;

}
