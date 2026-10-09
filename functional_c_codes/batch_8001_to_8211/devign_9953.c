/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9953
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1dc42050185d63c1de5d16146fbaee92640af187
 */

static int start_frame(AVFilterLink *inlink, AVFilterBufferRef *inpicref)

{

    AVFilterLink *outlink = inlink->dst->outputs[0];

    AVFilterBufferRef *outpicref = NULL;

    int ret = 0;



    if (inpicref->perms & AV_PERM_PRESERVE) {

        outpicref = ff_get_video_buffer(outlink, AV_PERM_WRITE,

                                        outlink->w, outlink->h);

        if (!outpicref)

            return AVERROR(ENOMEM);



        avfilter_copy_buffer_ref_props(outpicref, inpicref);

        outpicref->video->w = outlink->w;

        outpicref->video->h = outlink->h;

    } else {

        outpicref = avfilter_ref_buffer(inpicref, ~0);

        if (!outpicref)

            return AVERROR(ENOMEM);

    }



    ret = ff_start_frame(outlink, avfilter_ref_buffer(outpicref, ~0));

    if (ret < 0) {

        avfilter_unref_bufferp(&outpicref);

        return ret;

    }



    outlink->out_buf = outpicref;

    return 0;

}
