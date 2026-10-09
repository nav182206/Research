/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5589
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=eb19d89d8eb51f20299d59558d69d0f057583e7c
 */

static int64_t cache_seek(URLContext *h, int64_t pos, int whence)

{

    Context *c= h->priv_data;



    if (whence == AVSEEK_SIZE) {

        pos= ffurl_seek(c->inner, pos, whence);

        if(pos <= 0){

            pos= ffurl_seek(c->inner, -1, SEEK_END);

            ffurl_seek(c->inner, c->end, SEEK_SET);

            if(pos <= 0)

                return c->end;

        }

        return pos;

    }



    pos= lseek(c->fd, pos, whence);

    if(pos<0){

        return pos;

    }else if(pos <= c->end){

        c->pos= pos;

        return pos;

    }else{

        lseek(c->fd, c->pos, SEEK_SET);

        return AVERROR(EPIPE);

    }

}
