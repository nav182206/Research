/* 
 * Benchmark Sample ID : devign_537
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2758cdedfb7ac61f8b5e4861f99218b6fd43491d
 */

static const AVClass *urlcontext_child_class_next(const AVClass *prev)

{

    URLProtocol *p = NULL;



    /* find the protocol that corresponds to prev */

    while (prev && (p = ffurl_protocol_next(p)))

        if (p->priv_data_class == prev)

            break;



    /* find next protocol with priv options */

    while (p = ffurl_protocol_next(p))

        if (p->priv_data_class)

            return p->priv_data_class;

    return NULL;

}
