/* 
 * Benchmark Sample ID : devign_9230
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2f11aa141a01f97c5d2a015bd9dbdb27314b79c4
 */

static int vf_open(vf_instance_t *vf, char *args)

{

        vf->config=config;

        vf->query_format=query_format;

        vf->put_image=put_image;

        vf->uninit=uninit;



        vf->priv = calloc(1, sizeof (struct vf_priv_s));

        vf->priv->skipline = 0;

        vf->priv->scalew = 1;

        vf->priv->scaleh = 2;

        if (args) sscanf(args, "%d:%d:%d", &vf->priv->skipline, &vf->priv->scalew, &vf->priv->scaleh);



        return 1;

}
