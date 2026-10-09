/* 
 * Benchmark Sample ID : devign_6337
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4cc896ea5f06f8b1ebcde6d876d9c5b59ef9a016
 */

void av_register_input_format(AVInputFormat *format)

{

    AVInputFormat **p = last_iformat;



    format->next = NULL;

    while(*p || avpriv_atomic_ptr_cas((void * volatile *)p, NULL, format))

        p = &(*p)->next;

    last_iformat = &format->next;

}
