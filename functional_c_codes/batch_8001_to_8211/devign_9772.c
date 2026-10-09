/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9772
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=84c202cc37024bd78261e4222e46631ea73c48dd
 */

static int read_len_table(uint8_t *dst, GetBitContext *gb){

    int i, val, repeat;



    for(i=0; i<256;){

        repeat= get_bits(gb, 3);

        val   = get_bits(gb, 5);

        if(repeat==0)

            repeat= get_bits(gb, 8);

//printf("%d %d\n", val, repeat);

        if(i+repeat > 256) {

            av_log(NULL, AV_LOG_ERROR, "Error reading huffman table\n");

            return -1;

        }

        while (repeat--)

            dst[i++] = val;

    }

    return 0;

}
