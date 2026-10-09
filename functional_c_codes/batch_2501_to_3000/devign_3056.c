/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3056
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d29811806067de1516c2f94c0a81885fe2076fc8
 */

static target_long monitor_get_ccr (const struct MonitorDef *md, int val)

{

    CPUArchState *env = mon_get_cpu();

    unsigned int u;

    int i;



    u = 0;

    for (i = 0; i < 8; i++)

        u |= env->crf[i] << (32 - (4 * i));



    return u;

}
