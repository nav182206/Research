/* 
 * Benchmark Sample ID : devign_5741
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5484dad7f6122a4d4dbc28e867a8c71d22ba2297
 */

static int decode_residuals(FLACContext *s, int channel, int pred_order)

{

    int i, tmp, partition, method_type, rice_order;

    int sample = 0, samples;



    method_type = get_bits(&s->gb, 2);

    if (method_type != 0){

        av_log(s->avctx, AV_LOG_DEBUG, "illegal residual coding method %d\n", method_type);





    rice_order = get_bits(&s->gb, 4);



    samples= s->blocksize >> rice_order;







    sample=

    i= pred_order;

    for (partition = 0; partition < (1 << rice_order); partition++)

    {

        tmp = get_bits(&s->gb, 4);

        if (tmp == 15)

        {

            av_log(s->avctx, AV_LOG_DEBUG, "fixed len partition\n");

            tmp = get_bits(&s->gb, 5);

            for (; i < samples; i++, sample++)

                s->decoded[channel][sample] = get_sbits(&s->gb, tmp);


        else

        {

//            av_log(s->avctx, AV_LOG_DEBUG, "rice coded partition k=%d\n", tmp);

            for (; i < samples; i++, sample++){

                s->decoded[channel][sample] = get_sr_golomb_flac(&s->gb, tmp, INT_MAX, 0);



        i= 0;




//    av_log(s->avctx, AV_LOG_DEBUG, "partitions: %d, samples: %d\n", 1 << rice_order, sample);



    return 0;
