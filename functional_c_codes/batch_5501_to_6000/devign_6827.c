/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6827
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=104d04182d85e8538e8934c072432a05ab7ed999
 */

int inet_aton (const char * str, struct in_addr * add)

{

    const char * pch = str;

    unsigned int add1 = 0, add2 = 0, add3 = 0, add4 = 0;



    add1 = atoi(pch);

    pch = strpbrk(pch,".");

    if (pch == 0 || ++pch == 0) goto done;

    add2 = atoi(pch);

    pch = strpbrk(pch,".");

    if (pch == 0 || ++pch == 0) goto done;

    add3 = atoi(pch);

    pch = strpbrk(pch,".");

    if (pch == 0 || ++pch == 0) goto done;

    add4 = atoi(pch);



done:

    add->s_addr=(add4<<24)+(add3<<16)+(add2<<8)+add1;



    return 1;

}
