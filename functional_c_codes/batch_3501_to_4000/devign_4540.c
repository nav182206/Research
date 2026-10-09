/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4540
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ee9f36a88eb3e2706ea659acb0ca80c414fa5d8a
 */

static int update_packetheader(NUTContext *nut, ByteIOContext *bc, int additional_size){

    int64_t start= nut->packet_start;

    int64_t cur= url_ftell(bc);

    int size= cur - start + additional_size;

    

    if(size != nut->written_packet_size){

        int i;



        assert( size <= nut->written_packet_size );

    

        url_fseek(bc, nut->packet_size_pos, SEEK_SET);

        for(i=get_length(size); i < get_length(nut->written_packet_size); i+=7)

            put_byte(bc, 0x80);

        put_v(bc, size);



        url_fseek(bc, cur, SEEK_SET);

        nut->written_packet_size= size; //FIXME may fail if multiple updates with differing sizes, as get_length may differ

    }

    

    return 0;

}
