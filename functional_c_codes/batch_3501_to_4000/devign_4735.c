/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4735
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=019dd2365729d44d66a5b629102e1ecb919f4f67
 */

void av_get_channel_layout_string(char *buf, int buf_size,

                                  int nb_channels, uint64_t channel_layout)

{

    int i;



    if (nb_channels <= 0)

        nb_channels = av_get_channel_layout_nb_channels(channel_layout);



    for (i = 0; channel_layout_map[i].name; i++)

        if (nb_channels    == channel_layout_map[i].nb_channels &&

            channel_layout == channel_layout_map[i].layout) {

            av_strlcpy(buf, channel_layout_map[i].name, buf_size);

            return;

        }



    snprintf(buf, buf_size, "%d channels", nb_channels);

    if (channel_layout) {

        int i, ch;

        av_strlcat(buf, " (", buf_size);

        for (i = 0, ch = 0; i < 64; i++) {

            if ((channel_layout & (1L << i))) {

                const char *name = get_channel_name(i);

                if (name) {

                    if (ch > 0)

                        av_strlcat(buf, "|", buf_size);

                    av_strlcat(buf, name, buf_size);

                }

                ch++;

            }

        }

        av_strlcat(buf, ")", buf_size);

    }

}
