/* 
 * Benchmark Sample ID : devign_2756
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8af4ac5272e8eaff90c3102b9473bb09cc6f4201
 */

static int64_t mmsh_read_seek(URLContext *h, int stream_index,

                        int64_t timestamp, int flags)

{

    MMSHContext *mmsh = h->priv_data;

    MMSContext *mms   = &mmsh->mms;

    int ret;



    ret= mmsh_open_internal(h, mmsh->location, 0, timestamp, 0);

    if(ret>=0){

        if (mms->mms_hd)

            ffurl_close(mms->mms_hd);

        av_freep(&mms->streams);

        av_freep(&mms->asf_header);

        av_free(mmsh);

        mmsh = h->priv_data;

        mms   = &mmsh->mms;

        mms->asf_header_read_size= mms->asf_header_size;

    }else

        h->priv_data= mmsh;

    return ret;

}
