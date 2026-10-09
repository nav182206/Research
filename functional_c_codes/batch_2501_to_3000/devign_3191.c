/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3191
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a606f27f4c610708fa96e35eed7b7537d3d8f712
 */

int avio_read(AVIOContext *s, unsigned char *buf, int size)

{

    int len, size1;



    size1 = size;

    while (size > 0) {

        len = FFMIN(s->buf_end - s->buf_ptr, size);

        if (len == 0 || s->write_flag) {

            if((s->direct || size > s->buffer_size) && !s->update_checksum) {

                // bypass the buffer and read data directly into buf

                if(s->read_packet)

                    len = s->read_packet(s->opaque, buf, size);

                else

                    len = AVERROR_EOF;

                if (len == AVERROR_EOF) {

                    /* do not modify buffer if EOF reached so that a seek back can

                    be done without rereading data */

                    s->eof_reached = 1;

                    break;

                } else if (len < 0) {

                    s->eof_reached = 1;

                    s->error= len;

                    break;

                } else {

                    s->pos += len;

                    s->bytes_read += len;

                    size -= len;

                    buf += len;

                    // reset the buffer

                    s->buf_ptr = s->buffer;

                    s->buf_end = s->buffer/* + len*/;

                }

            } else {

                fill_buffer(s);

                len = s->buf_end - s->buf_ptr;

                if (len == 0)

                    break;

            }

        } else {

            memcpy(buf, s->buf_ptr, len);

            buf += len;

            s->buf_ptr += len;

            size -= len;

        }

    }

    if (size1 == size) {

        if (s->error)      return s->error;

        if (avio_feof(s))  return AVERROR_EOF;

    }

    return size1 - size;

}
