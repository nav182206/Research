/* 
 * Benchmark Sample ID : devign_3073
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cfcd396bae11de94ad4a729361bc9b7b05f04c27
 */

static void allocate_buffers(FLACContext *s){

    int i;



    assert(s->max_blocksize);



    if(s->max_framesize == 0 && s->max_blocksize){

        s->max_framesize= (s->channels * s->bps * s->max_blocksize + 7)/ 8; //FIXME header overhead

    }



    for (i = 0; i < s->channels; i++)

    {

        s->decoded[i] = av_realloc(s->decoded[i], sizeof(int32_t)*s->max_blocksize);

    }



    s->bitstream= av_fast_realloc(s->bitstream, &s->allocated_bitstream_size, s->max_framesize);

}
