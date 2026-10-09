/* 
 * Benchmark Sample ID : devign_556
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a6e14edde01bafbbe54f6f451efa718a48975b47
 */

static int http_send_data(HTTPContext *c)

{

    int len, ret;



    while (c->buffer_ptr >= c->buffer_end) {

        ret = http_prepare_data(c);

        if (ret < 0)

            return -1;

        else if (ret == 0) {

            break;

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

        }

    }

    return 0;

}
