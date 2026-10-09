/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3878
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e7d81004e486b0e80a674d164d8aec0e83fa812f
 */

static void audio_pp_nb_voices (const char *typ, int nb)

{

    switch (nb) {

    case 0:

        printf ("Does not support %s\n", typ);

        break;

    case 1:

        printf ("One %s voice\n", typ);

        break;

    case INT_MAX:

        printf ("Theoretically supports many %s voices\n", typ);

        break;

    default:

        printf ("Theoretically supports upto %d %s voices\n", nb, typ);

        break;

    }



}
