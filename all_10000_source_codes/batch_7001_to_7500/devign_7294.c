/* 
 * Benchmark Sample ID : devign_7294
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0d7937974cd0504f30ad483c3368b21da426ddf9
 */

static inline int vmsvga_fifo_length(struct vmsvga_state_s *s)

{

    int num;

    if (!s->config || !s->enable)

        return 0;

    num = CMD(next_cmd) - CMD(stop);

    if (num < 0)

        num += CMD(max) - CMD(min);

    return num >> 2;

}
