/* 
 * Benchmark Sample ID : devign_4924
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ad2a08388c82bdec5ac9355ca6e0bc4c98b26423
 */

static av_cold int concat_open(URLContext *h, const char *uri, int flags)

{

    char *node_uri = NULL;

    int err = 0;

    int64_t size;

    size_t  len, i;

    URLContext *uc;

    struct concat_data  *data = h->priv_data;

    struct concat_nodes *nodes;



    av_strstart(uri, "concat:", &uri);



    for (i = 0, len = 1; uri[i]; i++)

        if (uri[i] == *AV_CAT_SEPARATOR)

            /* integer overflow */

            if (++len == UINT_MAX / sizeof(*nodes)) {

                av_freep(&h->priv_data);

                return AVERROR(ENAMETOOLONG);

            }



    if (!(nodes = av_malloc(sizeof(*nodes) * len))) {

        return AVERROR(ENOMEM);

    } else

        data->nodes = nodes;



    /* handle input */

    if (!*uri)

        err = AVERROR(ENOENT);

    for (i = 0; *uri; i++) {

        /* parsing uri */

        len = strcspn(uri, AV_CAT_SEPARATOR);

        if ((err = av_reallocp(&node_uri, len + 1)) < 0)

            break;

        av_strlcpy(node_uri, uri, len+1);

        uri += len + strspn(uri+len, AV_CAT_SEPARATOR);



        /* creating URLContext */

        if ((err = ffurl_open(&uc, node_uri, flags,

                              &h->interrupt_callback, NULL)) < 0)

            break;



        /* creating size */

        if ((size = ffurl_size(uc)) < 0) {

            ffurl_close(uc);

            err = AVERROR(ENOSYS);

            break;

        }



        /* assembling */

        nodes[i].uc   = uc;

        nodes[i].size = size;

    }

    av_free(node_uri);

    data->length = i;



    if (err < 0)

        concat_close(h);

    else if ((err = av_reallocp(&nodes, data->length * sizeof(*nodes))) < 0)

        concat_close(h);

    else

        data->nodes = nodes;

    return err;

}
