/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5779
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fb60105d4942a26f571b1be92a8b9e7528d0c4d8
 */

static int ide_drive_pio_post_load(void *opaque, int version_id)

{

    IDEState *s = opaque;



    if (s->end_transfer_fn_idx > ARRAY_SIZE(transfer_end_table)) {

        return -EINVAL;

    }

    s->end_transfer_func = transfer_end_table[s->end_transfer_fn_idx];

    s->data_ptr = s->io_buffer + s->cur_io_buffer_offset;

    s->data_end = s->data_ptr + s->cur_io_buffer_len;



    return 0;

}
