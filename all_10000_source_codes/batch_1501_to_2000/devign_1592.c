/* 
 * Benchmark Sample ID : devign_1592
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0ffea3565700c9b3093ead285f729bb319a2163e
 */

int av_stream_add_side_data(AVStream *st, enum AVPacketSideDataType type,

                            uint8_t *data, size_t size)

{

    AVPacketSideData *sd, *tmp;

    int i;



    for (i = 0; i < st->nb_side_data; i++) {

        sd = &st->side_data[i];



        if (sd->type == type) {

            av_freep(&sd->data);

            sd->data = data;

            sd->size = size;

            return 0;

        }

    }



    tmp = av_realloc_array(st->side_data, st->nb_side_data + 1, sizeof(*tmp));

    if (!tmp) {

        return AVERROR(ENOMEM);

    }



    st->side_data = tmp;

    st->nb_side_data++;



    sd = &st->side_data[st->nb_side_data - 1];

    sd->type = type;

    sd->data = data;

    sd->size = size;



    return 0;

}
