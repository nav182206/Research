/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7406
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=14e4e26559697cfdea584767be4e68474a0a9c7f
 */

static int t37(InterplayACMContext *s, unsigned ind, unsigned col)

{

    GetBitContext *gb = &s->gb;

    unsigned i, b;

    int n1, n2;

    for (i = 0; i < s->rows; i++) {

        /* b = (x1) + (x2 * 11) */

        b = get_bits(gb, 7);







        n1 =  (mul_2x11[b] & 0x0F) - 5;

        n2 = ((mul_2x11[b] >> 4) & 0x0F) - 5;



        set_pos(s, i++, col, n1);

        if (i >= s->rows)

            break;

        set_pos(s, i, col, n2);


    return 0;
