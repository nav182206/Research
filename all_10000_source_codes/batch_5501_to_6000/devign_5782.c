/* 
 * Benchmark Sample ID : devign_5782
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e8c93839148a168aedc978388f14c3599dd072f8
 */

static int check_pes(uint8_t *p, uint8_t *end){

    int pes1;

    int pes2=      (p[3] & 0xC0) == 0x80

                && (p[4] & 0xC0) != 0x40

                &&((p[4] & 0xC0) == 0x00 || (p[4]&0xC0)>>2 == (p[6]&0xF0));



    for(p+=3; p<end && *p == 0xFF; p++);

    if((*p&0xC0) == 0x40) p+=2;

    if((*p&0xF0) == 0x20){

        pes1= p[0]&p[2]&p[4]&1;

        p+=5;

    }else if((*p&0xF0) == 0x30){

        pes1= p[0]&p[2]&p[4]&p[5]&p[7]&p[9]&1;

        p+=10;

    }else

        pes1 = *p == 0x0F;



    return pes1||pes2;

}
