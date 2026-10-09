/* 
 * Benchmark Sample ID : devign_4443
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ab2bfb85d49b2f8aa505816f93e75fd18ad0a361
 */

int ff_insert_pad(unsigned idx, unsigned *count, size_t padidx_off,

                   AVFilterPad **pads, AVFilterLink ***links,

                   AVFilterPad *newpad)

{

    AVFilterLink **newlinks;

    AVFilterPad *newpads;

    unsigned i;



    idx = FFMIN(idx, *count);



    newpads  = av_realloc_array(*pads,  *count + 1, sizeof(AVFilterPad));

    newlinks = av_realloc_array(*links, *count + 1, sizeof(AVFilterLink*));

    if (newpads)

        *pads  = newpads;

    if (newlinks)

        *links = newlinks;

    if (!newpads || !newlinks)

        return AVERROR(ENOMEM);



    memmove(*pads  + idx + 1, *pads  + idx, sizeof(AVFilterPad)   * (*count - idx));

    memmove(*links + idx + 1, *links + idx, sizeof(AVFilterLink*) * (*count - idx));

    memcpy(*pads + idx, newpad, sizeof(AVFilterPad));

    (*links)[idx] = NULL;



    (*count)++;

    for (i = idx + 1; i < *count; i++)

        if (*links[i])

            (*(unsigned *)((uint8_t *) *links[i] + padidx_off))++;



    return 0;

}
