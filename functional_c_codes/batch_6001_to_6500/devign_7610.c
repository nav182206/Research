/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7610
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6df5718bd3ec56225c44cf96440c723c1b611b87
 */

static MegasasCmd *megasas_next_frame(MegasasState *s,

    hwaddr frame)

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
