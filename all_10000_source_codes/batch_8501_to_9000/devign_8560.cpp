/* 
 * Benchmark Sample ID : devign_8560
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=14b6adfd4627421223894c6909476d229cb6d07d
 */

static void dequantize_slice_buffered(SnowContext *s, slice_buffer * sb, SubBand *b, IDWTELEM *src, int stride, int start_y, int end_y){

    const int w= b->width;

    const int qlog= av_clip(s->qlog + b->qlog, 0, QROOT*16);

    const int qmul= ff_qexp[qlog&(QROOT-1)]<<(qlog>>QSHIFT);

    const int qadd= (s->qbias*qmul)>>QBIAS_SHIFT;

    int x,y;



    if(s->qlog == LOSSLESS_QLOG) return;



    for(y=start_y; y<end_y; y++){

//        DWTELEM * line = slice_buffer_get_line_from_address(sb, src + (y * stride));

        IDWTELEM * line = slice_buffer_get_line(sb, (y * b->stride_line) + b->buf_y_offset) + b->buf_x_offset;

        for(x=0; x<w; x++){

            int i= line[x];

            if(i<0){

                line[x]= -((-i*qmul + qadd)>>(QEXPSHIFT)); //FIXME try different bias

            }else if(i>0){

                line[x]=  (( i*qmul + qadd)>>(QEXPSHIFT));

            }

        }

    }

}
