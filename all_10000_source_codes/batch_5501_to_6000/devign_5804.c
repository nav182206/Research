/* 
 * Benchmark Sample ID : devign_5804
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0d7937974cd0504f30ad483c3368b21da426ddf9
 */

static inline uint32_t vmsvga_fifo_read_raw(struct vmsvga_state_s *s)

{

    uint32_t cmd = s->fifo[CMD(stop) >> 2];

    s->cmd->stop = cpu_to_le32(CMD(stop) + 4);

    if (CMD(stop) >= CMD(max))

        s->cmd->stop = s->cmd->min;

    return cmd;

}
