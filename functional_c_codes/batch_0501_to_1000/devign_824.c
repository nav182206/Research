/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_824
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5279141c1d7a72c467b7e0666fc2275cbcec4668
 */

static void xan_unpack(unsigned char *dest, const unsigned char *src, int dest_len)

{

    unsigned char opcode;

    int size;

    unsigned char *dest_end = dest + dest_len;



    while (dest < dest_end) {

        opcode = *src++;



        if (opcode < 0xe0) {

            int size2, back;

            if ( (opcode & 0x80) == 0 ) {



                size = opcode & 3;



                back  = ((opcode & 0x60) << 3) + *src++ + 1;

                size2 = ((opcode & 0x1c) >> 2) + 3;



            } else if ( (opcode & 0x40) == 0 ) {



                size = *src >> 6;



                back  = (bytestream_get_be16(&src) & 0x3fff) + 1;

                size2 = (opcode & 0x3f) + 4;



            } else {



                size = opcode & 3;



                back  = ((opcode & 0x10) << 12) + bytestream_get_be16(&src) + 1;

                size2 = ((opcode & 0x0c) <<  6) + *src++ + 5;

                if (size + size2 > dest_end - dest)

                    return;

            }

            memcpy(dest, src, size);  dest += size;  src += size;

            av_memcpy_backptr(dest, back, size2);

            dest += size2;

        } else {

            int finish = opcode >= 0xfc;

            size = finish ? opcode & 3 : ((opcode & 0x1f) << 2) + 4;



            memcpy(dest, src, size);  dest += size;  src += size;

            if (finish)

                return;

        }

    }

}
