/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_624
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=14e4e26559697cfdea584767be4e68474a0a9c7f
 */

static int t15(InterplayACMContext *s, unsigned ind, unsigned col)

{

    GetBitContext *gb = &s->gb;

    unsigned i, b;

    int n1, n2, n3;



    for (i = 0; i < s->rows; i++) {

        /* b = (x1) + (x2 * 3) + (x3 * 9) */

        b = get_bits(gb, 5);







        n1 =  (mul_3x3[b] & 0x0F) - 1;

        n2 = ((mul_3x3[b] >> 4) & 0x0F) - 1;

        n3 = ((mul_3x3[b] >> 8) & 0x0F) - 1;



        set_pos(s, i++, col, n1);

        if (i >= s->rows)

            break;

        set_pos(s, i++, col, n2);

        if (i >= s->rows)

            break;

        set_pos(s, i, col, n3);


    return 0;
