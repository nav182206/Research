/* 
 * Benchmark Sample ID : devign_9493
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c780b543e72141393ae3c0b0cb2654f9a5e35f73
 */

void ff_id3v2_free_extra_meta(ID3v2ExtraMeta **extra_meta)

{

    ID3v2ExtraMeta *current = *extra_meta, *next;

    void (*free_func)(ID3v2ExtraMeta*);



    while (current) {

        if ((free_func = get_extra_meta_func(current->tag, 1)->free))

            free_func(current->data);

        next = current->next;

        av_freep(&current);

        current = next;

    }

}
