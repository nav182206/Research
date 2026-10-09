/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9408
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=da66b6313e61a861321b7d62a3d12a38877784bb
 */

static void quantize(SnowContext *s, SubBand *b, DWTELEM *src, int stride, int bias){

    const int level= b->level;

    const int w= b->width;

    const int h= b->height;

    const int qlog= clip(s->qlog + b->qlog, 0, 128);

    const int qmul= qexp[qlog&7]<<(qlog>>3);

    int x,y;



    assert(QROOT==8);



    bias= bias ? 0 : (3*qmul)>>3;

    

    if(!bias){

        for(y=0; y<h; y++){

            for(x=0; x<w; x++){

                int i= src[x + y*stride]; 

                //FIXME use threshold

                //FIXME optimize

                //FIXME bias

                if(i>=0){

                    i<<= QEXPSHIFT;

                    i/= qmul;

                    src[x + y*stride]=  i;

                }else{

                    i= -i;

                    i<<= QEXPSHIFT;

                    i/= qmul;

                    src[x + y*stride]= -i;

                }

            }

        }

    }else{

        for(y=0; y<h; y++){

            for(x=0; x<w; x++){

                int i= src[x + y*stride]; 

                

                //FIXME use threshold

                //FIXME optimize

                //FIXME bias

                if(i>=0){

                    i<<= QEXPSHIFT;

                    i= (i + bias) / qmul;

                    src[x + y*stride]=  i;

                }else{

                    i= -i;

                    i<<= QEXPSHIFT;

                    i= (i + bias) / qmul;

                    src[x + y*stride]= -i;

                }

            }

        }

    }

}
