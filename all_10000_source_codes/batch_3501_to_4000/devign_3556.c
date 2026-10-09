/* 
 * Benchmark Sample ID : devign_3556
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ee9794ed20528c2aa4c53cf67cb218bdce6e0485
 */

void av_dynarray_add(void *tab_ptr, int *nb_ptr, void *elem)

{

    /* see similar ffmpeg.c:grow_array() */

    int nb, nb_alloc;

    intptr_t *tab;



    nb = *nb_ptr;

    tab = *(intptr_t**)tab_ptr;

    if ((nb & (nb - 1)) == 0) {

        if (nb == 0)

            nb_alloc = 1;

        else

            nb_alloc = nb * 2;

        tab = av_realloc(tab, nb_alloc * sizeof(intptr_t));

        *(intptr_t**)tab_ptr = tab;

    }

    tab[nb++] = (intptr_t)elem;

    *nb_ptr = nb;

}
