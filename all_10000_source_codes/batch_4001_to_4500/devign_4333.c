/* 
 * Benchmark Sample ID : devign_4333
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4527ec2216109867498edc3ac8a17fd879b5d017
 */

static int decode_blocks(SnowContext *s){

    int x, y;

    int w= s->b_width;

    int h= s->b_height;

    int res;



    for(y=0; y<h; y++){

        for(x=0; x<w; x++){



            if ((res = decode_q_branch(s, 0, x, y)) < 0)

                return res;

        }

    }

    return 0;

}
