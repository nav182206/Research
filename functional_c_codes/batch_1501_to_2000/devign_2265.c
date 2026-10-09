/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2265
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static MegasasCmd *megasas_enqueue_frame(MegasasState *s,

    target_phys_addr_t frame, uint64_t context, int count)

{

    MegasasCmd *cmd = NULL;

    int frame_size = MFI_FRAME_SIZE * 16;

    target_phys_addr_t frame_size_p = frame_size;



    cmd = megasas_next_frame(s, frame);

    /* All frames busy */

    if (!cmd) {

        return NULL;

    }

    if (!cmd->pa) {

        cmd->pa = frame;

        /* Map all possible frames */

        cmd->frame = cpu_physical_memory_map(frame, &frame_size_p, 0);

        if (frame_size_p != frame_size) {

            trace_megasas_qf_map_failed(cmd->index, (unsigned long)frame);

            if (cmd->frame) {

                cpu_physical_memory_unmap(cmd->frame, frame_size_p, 0, 0);

                cmd->frame = NULL;

                cmd->pa = 0;

            }

            s->event_count++;

            return NULL;

        }

        cmd->pa_size = frame_size_p;

        cmd->context = context;

        if (!megasas_use_queue64(s)) {

            cmd->context &= (uint64_t)0xFFFFFFFF;

        }

    }

    cmd->count = count;

    s->busy++;



    trace_megasas_qf_enqueue(cmd->index, cmd->count, cmd->context,

                             s->reply_queue_head, s->busy);



    return cmd;

}
