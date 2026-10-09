/* 
 * Benchmark Sample ID : devign_413
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static MegasasCmd *megasas_next_frame(MegasasState *s,

    target_phys_addr_t frame)

{

    MegasasCmd *cmd = NULL;

    int num = 0, index;



    cmd = megasas_lookup_frame(s, frame);

    if (cmd) {

        trace_megasas_qf_found(cmd->index, cmd->pa);

        return cmd;

    }

    index = s->reply_queue_head;

    num = 0;

    while (num < s->fw_cmds) {

        if (!s->frames[index].pa) {

            cmd = &s->frames[index];

            break;

        }

        index = megasas_next_index(s, index, s->fw_cmds);

        num++;

    }

    if (!cmd) {

        trace_megasas_qf_failed(frame);

    }

    trace_megasas_qf_new(index, cmd);

    return cmd;

}
