/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_748
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6265eb26a375179f193f792e4f0d49036d2cf052
 */

static int curl_open(BlockDriverState *bs, const char *filename, int flags)

{

    BDRVCURLState *s = bs->opaque;

    CURLState *state = NULL;

    double d;



    #define RA_OPTSTR ":readahead="

    char *file;

    char *ra;

    const char *ra_val;

    int parse_state = 0;



    static int inited = 0;



    file = strdup(filename);

    s->readahead_size = READ_AHEAD_SIZE;



    /* Parse a trailing ":readahead=#:" param, if present. */

    ra = file + strlen(file) - 1;

    while (ra >= file) {

        if (parse_state == 0) {

            if (*ra == ':')

                parse_state++;

            else

                break;

        } else if (parse_state == 1) {

            if (*ra > '9' || *ra < '0') {

                char *opt_start = ra - strlen(RA_OPTSTR) + 1;

                if (opt_start > file &&

                    strncmp(opt_start, RA_OPTSTR, strlen(RA_OPTSTR)) == 0) {

                    ra_val = ra + 1;

                    ra -= strlen(RA_OPTSTR) - 1;

                    *ra = '\0';

                    s->readahead_size = atoi(ra_val);

                    break;

                } else {

                    break;

                }

            }

        }

        ra--;

    }



    if ((s->readahead_size & 0x1ff) != 0) {

        fprintf(stderr, "HTTP_READAHEAD_SIZE %zd is not a multiple of 512\n",

                s->readahead_size);

        goto out_noclean;

    }



    if (!inited) {

        curl_global_init(CURL_GLOBAL_ALL);

        inited = 1;

    }



    DPRINTF("CURL: Opening %s\n", file);

    s->url = file;

    state = curl_init_state(s);

    if (!state)

        goto out_noclean;



    // Get file size



    curl_easy_setopt(state->curl, CURLOPT_NOBODY, 1);

    curl_easy_setopt(state->curl, CURLOPT_WRITEFUNCTION, (void *)curl_size_cb);

    if (curl_easy_perform(state->curl))

        goto out;

    curl_easy_getinfo(state->curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &d);

    curl_easy_setopt(state->curl, CURLOPT_WRITEFUNCTION, (void *)curl_read_cb);

    curl_easy_setopt(state->curl, CURLOPT_NOBODY, 0);

    if (d)

        s->len = (size_t)d;

    else if(!s->len)

        goto out;

    DPRINTF("CURL: Size = %lld\n", (long long)s->len);



    curl_clean_state(state);

    curl_easy_cleanup(state->curl);

    state->curl = NULL;



    // Now we know the file exists and its size, so let's

    // initialize the multi interface!



    s->multi = curl_multi_init();

    curl_multi_setopt( s->multi, CURLMOPT_SOCKETDATA, s); 

    curl_multi_setopt( s->multi, CURLMOPT_SOCKETFUNCTION, curl_sock_cb ); 

    curl_multi_do(s);



    return 0;



out:

    fprintf(stderr, "CURL: Error opening file: %s\n", state->errmsg);

    curl_easy_cleanup(state->curl);

    state->curl = NULL;

out_noclean:

    qemu_free(file);

    return -EINVAL;

}
