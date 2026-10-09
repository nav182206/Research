/* 
 * Benchmark Sample ID : devign_3846
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5eb765ef341c3ec1bea31914c897750f88476ede
 */

static int http_send_data(HTTPContext *c, long cur_time)

{

    int len, ret;



    while (c->buffer_ptr >= c->buffer_end) {

        ret = http_prepare_data(c, cur_time);

        if (ret < 0)

            return -1;

        else if (ret == 0) {

            continue;

        } else {

            /* state change requested */

            return 0;

        }

    }



    if (c->buffer_end > c->buffer_ptr) {

        len = write(c->fd, c->buffer_ptr, c->buffer_end - c->buffer_ptr);

        if (len < 0) {

            if (errno != EAGAIN && errno != EINTR) {

                /* error : close connection */

                return -1;

            }

        } else {

            c->buffer_ptr += len;

            c->data_count += len;

            if (c->stream)

                c->stream->bytes_served += len;

        }

    }

    return 0;

}
