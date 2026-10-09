/* 
 * Benchmark Sample ID : devign_7075
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5f68a91be242c05bdd5aeffd74b36a1e6c782dd5
 */

int avfilter_default_config_output_link(AVFilterLink *link)

{

    if (link->src->input_count && link->src->inputs[0]) {

        if (link->type == AVMEDIA_TYPE_VIDEO) {

            link->w = link->src->inputs[0]->w;

            link->h = link->src->inputs[0]->h;

            link->time_base = link->src->inputs[0]->time_base;

        } else if (link->type == AVMEDIA_TYPE_AUDIO) {

            link->channel_layout = link->src->inputs[0]->channel_layout;

            link->sample_rate    = link->src->inputs[0]->sample_rate;

        }

    } else {

        /* XXX: any non-simple filter which would cause this branch to be taken

         * really should implement its own config_props() for this link. */

        return -1;

    }



    return 0;

}
