/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9241
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e774c41cab765f5d12ecfb31e5fa30df41230de0
 */

static inline void update_rice(APERice *rice, int x)

{

    rice->ksum += ((x + 1) / 2) - ((rice->ksum + 16) >> 5);



    if (rice->k == 0)

        rice->k = 1;

    else if (rice->ksum < (1 << (rice->k + 4)))

        rice->k--;

    else if (rice->ksum >= (1 << (rice->k + 5)))

        rice->k++;

}
