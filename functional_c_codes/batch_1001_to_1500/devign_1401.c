/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1401
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cc276c85d15272df6e44fb3252657a43cbd49555
 */

void av_get_channel_layout_string(char *buf, int buf_size,

                                  int nb_channels, int64_t channel_layout)

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
