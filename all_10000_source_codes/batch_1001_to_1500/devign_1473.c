/* 
 * Benchmark Sample ID : devign_1473
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4ea7c179325f61736040f2ff22c2f27c702727d4
 */

static int config_props(AVFilterLink *link)

{

    YADIFContext *yadif = link->src->priv;



    link->time_base.num = link->src->inputs[0]->time_base.num;

    link->time_base.den = link->src->inputs[0]->time_base.den * 2;

    link->w             = link->src->inputs[0]->w;

    link->h             = link->src->inputs[0]->h;



    if(yadif->mode&1)

        link->frame_rate = av_mul_q(link->src->inputs[0]->frame_rate, (AVRational){2,1});



    return 0;

}
