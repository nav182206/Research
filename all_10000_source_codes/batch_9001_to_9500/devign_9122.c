/* 
 * Benchmark Sample ID : devign_9122
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5a571d324129ce367584ad9d92aae1d286f389a2
 */

static void h264_free_context(PayloadContext *data)

{

#ifdef DEBUG

    int ii;



    for (ii = 0; ii < 32; ii++) {

        if (data->packet_types_received[ii])

            av_log(NULL, AV_LOG_DEBUG, "Received %d packets of type %d\n",

                   data->packet_types_received[ii], ii);

    }

#endif



    assert(data);

    assert(data->cookie == MAGIC_COOKIE);



    // avoid stale pointers (assert)

    data->cookie = DEAD_COOKIE;



    // and clear out this...

    av_free(data);

}
